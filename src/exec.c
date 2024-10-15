#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>

void file_info(char *filename) {
    struct stat filestat;
    if (stat(filename, &filestat) == -1) {
        perror("Erro ao obter informações do arquivo");
        return;
    }

    printf("Tamanho: %ld bytes\n", filestat.st_size);
    printf("Permissões: %o\n", filestat.st_mode & 0777);
    printf("Número de links: %ld\n", filestat.st_nlink);
}


void execute_command(char **args) {
    pid_t pid;
    int status;

    // Verifica se o comando é 'cd' e trata ele diretamente
    if (strcmp(args[0], "cd") == 0) {
        if (args[1] == NULL) {
            fprintf(stderr, "ShellZer0: esperado argumento para 'cd'\n");
        } else {
            if (chdir(args[1]) != 0) {
                perror("ShellZer0");
            }
        }
        return; // Não prosseguir com o fork se for o comando 'cd'
    }

    // Para outros comandos, cria um processo filho
    pid = fork();

    if (pid == 0) {
        // Processo filho: executa o comando
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

