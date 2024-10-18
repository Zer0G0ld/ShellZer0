#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>
#include "parser.h"
#include "colors.h"

// Prototipos de funções
char **parse_input(char *input);
void execute_command(char **args);
void load_zer0rc();
void display_welcome_message();
void handle_sigint(int sig);
void set_prompt();

// Estrutura para armazenar aliases
typedef struct Alias {
    char *name;
    char *command;
    struct Alias *next;
} Alias;

Alias *alias_list = NULL;

// Função para exibir a mensagem de boas-vindas
void display_welcome_message() {
    printf(BLUE "┏━(Mensagem dos desenvolvedores do Zer0)\n"RESET);
    printf(BLUE"┃\n"RESET);
    printf(BLUE"┃ Esta é uma instalação mínima do ShellZer0, você provavelmente\n"RESET);
    printf(BLUE"┃ deseja instalar ferramentas complementares. Saiba como:\n"RESET);
    printf(BLUE"┃ ⇒ https://github.com/Zer0G0ld/ShellZer0\n"RESET);
    printf(BLUE"┃\n"RESET);
    printf(BLUE"┗━(Execute: “nano ~/.zer0rc” para editar o shell)\n"RESET);

    // Exibe o diretório atual e o usuário
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("Diretório atual: %s\n", cwd);
    } else {
        perror("Erro ao obter diretório atual");
    }
}

// Função para tratar o sinal SIGINT (Ctrl+C)
void handle_sigint(int sig) {
    printf(BG_RED"\nInterrupção recebida (Ctrl+C). Digite 'exit' para sair.\n"RESET);
}

// Função para carregar o arquivo .zer0rc
void load_zer0rc() {
    char* home = getenv("HOME");
    if (!home) {
        printf("Diretório HOME não encontrado. Configuração não carregada.\n");
        return;
    }

    char path[256];
    snprintf(path, sizeof(path), "%s/.zer0rc", home);  // Cria o caminho para .zer0rc

    FILE *file = fopen(path, "r");
    if (file) {
        printf("Carregando configuração de %s\n", path);
        char line[256];
        while (fgets(line, sizeof(line), file)) {
            if (strncmp(line, "alias ", 6) == 0) {
                char* alias_cmd = strtok(line + 6, "=");
                char* alias_value = strtok(NULL, "\n");

                if (alias_cmd && alias_value) {
                    // Remove aspas da definição de alias
                    if (alias_value[0] == '"' && alias_value[strlen(alias_value) - 1] == '"') {
                        alias_value[strlen(alias_value) - 1] = '\0';
                        alias_value++;
                    }

                    // Cria um novo alias e adiciona à lista de aliases
                    Alias *new_alias = malloc(sizeof(Alias));
                    new_alias->name = strdup(alias_cmd);
                    new_alias->command = strdup(alias_value);
                    new_alias->next = alias_list;
                    alias_list = new_alias;

                    printf("Alias definido: %s -> %s\n", alias_cmd, alias_value);
                }
            }
        }
        fclose(file);
    } else {
        printf("Arquivo .zer0rc não encontrado. Criando um novo...\n");
        file = fopen(path, "w");
        if (file) {
            fprintf(file, "alias cls=\"clear\"\n");
            fclose(file);
            printf("Arquivo .zer0rc criado em %s.\n", path);
        } else {
            perror("Erro ao criar o arquivo .zer0rc");
        }
    }
}

// Função para configurar o prompt de acordo com o usuário
void set_prompt() {
    char cwd[1024];
    char *user = getenv("USER");
    char *home = getenv("HOME");
    char *last_dir;

    if (!user) user = "Zer0";  // Default user se não encontrar o USER
    if (getuid() == 0) user = "root";  // Nome de usuário 'root' para superusuário

    // Obtém o diretório atual
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        if (strncmp(cwd, home, strlen(home)) == 0) {
            last_dir = cwd + strlen(home);
            if (*last_dir == '/') last_dir++;

            // Modifica o prompt dependendo se o usuário é root ou não
            if (getuid() == 0) {
                printf("┌──(root㉿%s)-[~%s]\n└─$ ", "root", last_dir);  // Prompt para root
            } else {
                printf("┌──(%s㉿%s)-[~%s]\n└─$ ", user, user, last_dir);  // Prompt para usuários normais
            }
        } else {
            last_dir = strrchr(cwd, '/');
            if (last_dir != NULL) last_dir++;

            // Modifica o prompt dependendo se o usuário é root ou não
            if (getuid() == 0) {
                printf("┌──(root㉿%s)-[%s]\n└─$ ", "root", last_dir);  // Prompt para root
            } else {
                printf("┌──(%s㉿%s)-[%s]\n└─$ ", user, user, last_dir);  // Prompt para usuários normais
            }
        }
    } else {
        perror("Erro ao obter diretório atual");
    }
}

// Função para liberar a memória alocada para aliases
void free_aliases() {
    Alias *current = alias_list;
    while (current) {
        Alias *next = current->next;
        free(current->name);
        free(current->command);
        free(current);
        current = next;
    }
}

// Função principal do shell
int main() {
    char *input, **args;

    // Exibe a mensagem de boas-vindas
    display_welcome_message();

    // Carrega o .zer0rc ou cria um novo
    load_zer0rc();

    // Configura o tratamento de Ctrl+C (SIGINT)
    signal(SIGINT, handle_sigint);

    while (1) {
        // Chama a função para configurar o prompt baseado no usuário
        set_prompt();

        // Lê a entrada do usuário com histórico
        input = readline("");  // Exibe o prompt
        if (!input) {
            printf("Erro ou EOF detectado. Saindo...\n");
            break;
        }

        // Adiciona ao histórico, se o comando não for vazio
        if (*input) add_history(input);

        // Faz o parsing da entrada
        args = parse_input(input);

        if (args[0] == NULL) {
            free(input);
            continue;  // Ignora entradas vazias
        }

        if (strcmp(args[0], "exit") == 0) {
            free(input);
            break;
        }

        // Verifica se o comando corresponde a um alias
        Alias *current = alias_list;
        while (current) {
            if (strcmp(args[0], current->name) == 0) {
                printf("Alias encontrado: %s -> %s\n", current->name, current->command);
                free(input);  // Liberar apenas a entrada original
                args = parse_input(current->command);  // Aloca novos args baseados no alias
                break;  // Não libera args, pois agora ele foi sobrescrito
            }
            current = current->next;
        }

        // Executa o comando
        execute_command(args);

        // Libera memória alocada para os argumentos
        for (size_t i = 0; args[i] != NULL; i++) {
            free(args[i]);
        }
        free(args);  // Liberar após a execução
        free(input);  // Libera a entrada original
    }

    // Libera a memória alocada para aliases
    free_aliases();

    return 0;
}
