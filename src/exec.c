#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

// Função que executa o comando
void execute_command(char **args) {
    pid_t pid;
    int status;

    // Cria um processo filho
    pid = fork();

    if (pid == 0) {
        // Processo filho: tenta executar o comando
        if (execvp(args[0], args) == -1) {
            perror("Erro na execução");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Erro no fork
        perror("Erro ao criar processo");
    } else {
        // Processo pai: espera o filho terminar
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
}
