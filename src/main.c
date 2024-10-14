#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void execute_command(char **args);
char **parse_input(char *input);

int main() {
    char *input = NULL;
    size_t len = 0;
    char **args;

    while (1) {
        printf("ShellZer0> "); // Exibe o prompt da shell
        getline(&input, &len, stdin); // Lê a entrada do usuário

        input[strlen(input) - 1] = '\0'; // Remove o '\n'

        args = parse_input(input);

        if (strcmp(args[0], "exit") == 0) {
            break;
        }

        execute_command(args);

        free(args); // Libera a memória dos argumentos
    }

    free(input); // Libera a memória de input
    return 0;
}
