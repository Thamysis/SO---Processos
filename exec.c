#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("Erro ao criar o processo filho");
        return 1;
    }

    if (pid == 0) {
        printf("Eu sou o processo filho e vou executar o comando 'ls' usando exec.\n");

        execl("/bin/ls", "ls", "-l", NULL);

        perror("Erro ao executar exec");
        return 1;
        
    } else {
        printf("Eu sou o processo pai. Meu PID é %d e o PID do meu filho é %d\n", getpid(), pid);
        
        wait(NULL);
        printf("Processo filho terminou.\n");
    }

    return 0;
}
