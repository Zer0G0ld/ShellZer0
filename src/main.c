#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <readline/readline.h>
#include <readline/history.h>

void execute_command(char **args);
char **parse_input(char *input);

int main() {
    char *input;
    char **args, cwd[1024], *home, *last_dir;
    char *user = getenv("USER");

    if (!user) user = "Zer0";  // Usuário padrão se não encontrado
    if (getuid() == 0) user = "root";  // Se for root, altera o nome do usuário

    home = getenv("HOME");  // Pega o diretório HOME

    while (1) {
        // Obtém o diretório atual
        if (getcwd(cwd, sizeof(cwd)) != NULL) {
            // Se o diretório atual for o diretório HOME, substitui por ~
            if (strncmp(cwd, home, strlen(home)) == 0) {
                last_dir = cwd + strlen(home);
                if (*last_dir == '/') last_dir++;  // Remove a barra inicial se houver

                // Exibe o prompt com ~ para o diretório HOME
                printf("%s@~/%s$ ", user, last_dir);
            } else {
                // Exibe o caminho completo caso não seja o HOME
                last_dir = strrchr(cwd, '/');
                if (last_dir != NULL) last_dir++;  // Pega apenas o último diretório

                printf("%s@%s$ ", user, last_dir);
            }
        } else {
            perror("getcwd");
        }

        // Use readline para capturar a entrada do usuário com histórico
        input = readline("");  // Exibe o prompt

        // Adiciona o comando ao histórico, se não for nulo ou vazio
        if (input && *input) {
            add_history(input);
        }

        args = parse_input(input);

        if (strcmp(args[0], "exit") == 0) {
            free(input);
            break;
        }

        execute_command(args);

        free(args);  // Libera a memória dos argumentos
        free(input);  // Libera a memória de input
    }

    return 0;
}

