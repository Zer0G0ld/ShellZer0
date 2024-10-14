#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include "shell.h"

int main() {
    char *input = NULL;
    size_t len = 0;
    char **args;

    while (1) {
        printf("ShellZer0> ");
        getline(&input, &len, stdin);
        input[strlen(input) - 1] = '\0'; // Remove o \n

        args = parse_input(input);

        if (strcmp(args[0], "exit") == 0) {
            break;
        }

        if (strcmp(args[0], "cd") == 0) {
            if (args[1] == NULL) {
                fprintf(stderr, "ShellZer0: argumento esperado para \"cd\"\n");
            } else {
                if (chdir(args[1]) != 0) {
                    perror("ShellZer0");
                }
            }
            continue;
        }

        execute_command(args); // Executa comandos externos

        free(args);
    }

    free(input);
    return 0;
}

