#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <dirent.h>
#include <ctype.h>

#define PROC_PATH "/proc"

typedef struct {
    int pid;
    char name[256];
    char state;
    int priority;
    long long int rss;
} ProcessInfo;

int isNumeric(const char *str) {
    while (*str) {
        if (!isdigit(*str))
            return 0;
        str++;
    }
    return 1;
}

void readProcessInfo(int pid, ProcessInfo *process) {
    char path[256];
    snprintf(path, sizeof(path), PROC_PATH "/%d/stat", pid);

    FILE *fp = fopen(path, "r");
    if (fp) {
        fscanf(fp, "%d %s %c %d", &process->pid, process->name, &process->state, &process->priority);
        fclose(fp);
    }

    snprintf(path, sizeof(path), PROC_PATH "/%d/statm", pid);
    fp = fopen(path, "r");
    if (fp) {
        fscanf(fp, "%*d %lld", &process->rss);
        fclose(fp);
    }
}

void listProcesses() {
    DIR *dir = opendir(PROC_PATH);
    if (!dir) {
        perror("opendir");
        exit(1);
    }

    printf("%-8s %-20s %-8s %-8s\n", "PID", "NAME", "STATE", "RSS");

    struct dirent *entry;
    while ((entry = readdir(dir))) {
        if (isNumeric(entry->d_name)) {
            int pid = atoi(entry->d_name);
            ProcessInfo process;
            readProcessInfo(pid, &process);
            printf("%-8d %-20s %-8c %-8lld\n", process.pid, process.name, process.state, process.rss);
        }
    }

    closedir(dir);
}

int main() {
    while (1) {
        system("clear"); // Limpa a tela (Linux)
        listProcesses();
        usleep(500000); // Espera 0.5 segundos
    }

    return 0;
}
