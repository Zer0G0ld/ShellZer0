#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define o delimitador (no caso, espaço) para separar os comandos
#define DELIM " "

// Função que parseia a entrada do usuário
char **parse_input(char *input) {
    int bufsize = 64, i = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token;

    // Garante que a memória foi alocada corretamente
    if (!tokens) {
        fprintf(stderr, "Erro de alocação de memória\n");
        exit(EXIT_FAILURE);
    }

    // Usa strtok para dividir a string em tokens
    token = strtok(input, DELIM);
    while (token != NULL) {
        tokens[i] = token;
        i++;

        // Se o buffer for excedido, realoca mais espaço
        if (i >= bufsize) {
            bufsize += 64;
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if (!tokens) {
                fprintf(stderr, "Erro de alocação de memória\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, DELIM);
    }
    tokens[i] = NULL;  // Finaliza a lista de argumentos com NULL
    return tokens;
}
