#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void execute_command(char **args) {
    pid_t pid;
    int status;

    pid = fork();

    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("Erro na execução");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("Erro ao criar processo");
    } else {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}
