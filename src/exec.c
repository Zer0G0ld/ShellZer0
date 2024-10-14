#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        // Processo filho executa o comando
        if (execvp(args[0], args) == -1) {
            perror("Erro na execução");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Erro no fork
        perror("Erro ao criar processo");
    } else {
        // Processo pai espera o filho terminar
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}

