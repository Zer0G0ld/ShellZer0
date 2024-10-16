#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>
#include <signal.h>  
#include "parser.h"  

// Declaração do protótipo de parse_input
char **parse_input(char *input);

void execute_command(char **args);

// Função para exibir a mensagem personalizada
void display_welcome_message() {
    printf("┏━(Mensagem dos desenvolvedores do Zer0)\n");
    printf("┃\n");
    printf("┃ Esta é uma instalação mínima do ShellZer0, você provavelmente\n");
    printf("┃ deseja instalar ferramentas complementares. Saiba como:\n");
    printf("┃ ⇒ https://github.com/Zer0G0ld/ShellZer0\n");
    printf("┃\n");
    printf("┗━(Execute: “touch ~/.zer0rc” para ocultar esta mensagem)\n");

    // Exibe informações do sistema
    char cwd[1024];
    if (getcwd(cwd, sizeof(cwd)) != NULL) {
        char *user = getenv("USER");
        if (!user) user = "Zer0";  // Usuário padrão

//        printf("┌──(%s㉿%s)-[%s]\n", user, user, cwd);
//        printf("└─$\n");
    } else {
        perror("getcwd");
    }
}

// Função para tratar o sinal SIGINT (Ctrl+C)
void handle_sigint(int sig) {
    printf("\nInterrupção recebida (Ctrl+C). Digite 'exit' para sair.\n");
}

// Função main sem a definição de parse_input
int main() {
    char *input;
    char **args, cwd[1024], *home, *last_dir;
    char *user = getenv("USER");

    if (!user) user = "Zer0";  // Usuário padrão se não encontrado
    if (getuid() == 0) user = "root";  // Se for root, altera o nome do usuário

    home = getenv("HOME");  // Pega o diretório HOME

    // Exibe a mensagem personalizada no início
    display_welcome_message();

    // Captura o sinal SIGINT (Ctrl+C)
    signal(SIGINT, handle_sigint);

    while (1) {
        // Obtém o diretório atual
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            // Se o diretório atual for o diretório HOME, substitui por ~
            if (strncmp(cwd, home, strlen(home)) == 0) {
                last_dir = cwd + strlen(home);
                if (*last_dir == '/') last_dir++;  // Remove a barra inicial se houver

                // Exibe o prompt com ~ para o diretório HOME
                printf("┌──(%s㉿%s)-[%s]\n", user, user, last_dir);
                printf("└─$ ");
            } else {
                // Exibe o caminho completo caso não seja o HOME
                last_dir = strrchr(cwd, '/');
                if (last_dir != NULL) last_dir++;  // Pega apenas o último diretório
                printf("┌──(%s㉿%s)-[%s]\n", user, user, last_dir);
                printf("└─$ ");
            }
        } else {
            perror("getcwd");
        }

        // Use readline para capturar a entrada do usuário com histórico
        input = readline("");  // Exibe o prompt

        // Se o input for NULL, significa que houve erro ou EOF
        if (!input) {
            printf("Erro ou EOF detectado. Saindo...\n");
            break;
        }

        // Adiciona o comando ao histórico, se não for nulo ou vazio
        if (input && *input) {
            add_history(input);
        }

        args = parse_input(input);

        if (args[0] == NULL) {
            free(input);  // Libera a memória de input
            continue;     // Ignora entradas vazias
        }

        if (strcmp(args[0], "exit") == 0) {
            free(input);
            break;
        }

        execute_command(args);

        // Libera a memória dos argumentos
        for (int i = 0; args[i] != NULL; i++) {
            free(args[i]);
        }
        free(args);  // Libera o array de argumentos

        // Só libera 'input' uma vez, ao final do loop
        free(input);
    }

    return 0;
}
