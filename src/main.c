#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Funções que serão implementadas em outros arquivos
void execute_command(char **args);
char **parse_input(char *input);

int main() {
    char *input = NULL;
    size_t len = 0;
    char **args;

    while (1) {
        printf("ShellZer0> "); // Exibe o prompt da shell
        getline(&input, &len, stdin); // Lê a entrada do usuário

        // Remove o caractere de nova linha ('\n) ao final do input
        input[strlen(input) - 1] = '\0';

        // Parseia o comando e seus argumentos
        args = parse_input(input);

        // Se o comando for "exit", encerra o shell
        if (strcmp(args[0], "exit") == 0) {
            break;
        }

        // Executa o comando
        execute_command(args);

        // Libera a memória alocada para os argumentos
        free(args);
    }

    free(input); // Libera a memória alocada para a entrada
    return 0;
}