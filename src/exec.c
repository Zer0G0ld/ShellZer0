#include "parser.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>
#include <fcntl.h> // Para manipulação de arquivos
#include <sys/stat.h>
#include <signal.h>
//#include <sys/syscall.h>

// Função para invocar uma syscall personalizada
//void invoke_syscall() {
//    // No caso da syscall 'exit', por exemplo:
//    syscall(SYS_exit, 0);  // Chama a syscall 'exit' com código de saída 0
//}

// Função para obter informações sobre o arquivo
void file_info(char *filename) {
    struct stat filestat;
    if (stat(filename, &filestat) == -1) {
        perror("Erro ao obter informações do arquivo");
        return;
    }

    printf("Tamanho: %ld bytes\n", filestat.st_size);
    printf("Permissões: %o\n", filestat.st_mode & 0777);
    printf("Número de links: %u\n", filestat.st_nlink);
}

// Função para execução com redirecionamento
void execute_with_redirection(char **args) {
    pid_t pid;
    int status;
    int input_redirect = -1, output_redirect = -1;

    // Detecta redirecionamento de entrada/saída
    for (int i = 0; args[i] != NULL; i++) {
        if (strcmp(args[i], ">") == 0 && args[i+1] != NULL) {
            output_redirect = i;
        } else if (strcmp(args[i], "<") == 0 && args[i+1] != NULL) {
            input_redirect = i;
        }
    }

    pid = fork();
    if (pid == 0) { // Processo filho
        if (output_redirect != -1) {
            int fd = open(args[output_redirect + 1], O_CREAT | O_WRONLY | O_TRUNC, 0644);
            if (fd < 0) {
                perror("Erro ao abrir arquivo para saída");
                exit(EXIT_FAILURE);
            }
            dup2(fd, STDOUT_FILENO);
            close(fd);
            args[output_redirect] = NULL; // Remove '>' e o nome do arquivo
        } 

        if (input_redirect != -1) {
            int fd = open(args[input_redirect + 1], O_RDONLY);
            if (fd < 0) {
                perror("Erro ao abrir arquivo para entrada");
                exit(EXIT_FAILURE);
            }
            dup2(fd, STDIN_FILENO);
            close(fd);
            args[input_redirect] = NULL; // Remove '<' e o nome do arquivo
        }

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

// Função para execução com pipes
void execute_pipe(char **args1, char **args2) {
    int pipefd[2];
    pid_t pid1, pid2;

    if (pipe(pipefd) == -1) {
        perror("Erro ao criar pipe");
        return;
    }

    pid1 = fork();
    if (pid1 == 0) { // Processo 1
        close(pipefd[0]);
        dup2(pipefd[1], STDOUT_FILENO);
        close(pipefd[1]);

        if (execvp(args1[0], args1) == -1) {
            perror("Erro ao executar o primeiro comando");
            exit(EXIT_FAILURE);
        }
    } else if (pid1 < 0) {
        perror("Erro ao criar processo 1");
    } else {
        pid2 = fork();
        if (pid2 == 0) { // Processo 2
            close(pipefd[1]);
            dup2(pipefd[0], STDIN_FILENO);
            close(pipefd[0]);

            if (execvp(args2[0], args2) == -1) {
                perror("Erro ao executar o segundo comando");
                exit(EXIT_FAILURE);
            }
        } else if (pid2 < 0) {
            perror("Erro ao criar processo 2");
        }

        close(pipefd[0]);
        close(pipefd[1]);
        wait(NULL);
        wait(NULL);
    }
}

// Função para executar comandos
void execute_command(char **args) {
    if (args[0] == NULL) return; // Ignora comandos vazios

    if (strcmp(args[0], "exit") == 0) {
        exit(0);
    } 

    if (strcmp(args[0], "cd") == 0) {
        if (args[1] != NULL) {
            if (chdir(args[1]) != 0) {
                perror("Erro ao mudar de diretório");
            }
        } else {
            printf("Informe o diretório para mudar.\n");
        }
        return;
    }

    // Adiciona outras funcionalidades aqui (como pipes e redirecionamento)
    if (strchr(args[0], '|')) {
        char **args1 = parse_input(args[0]);
        char **args2 = parse_input(args[1]);
        execute_pipe(args1, args2);
    } else {
        execute_with_redirection(args);
    }
}
