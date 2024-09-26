#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main() {
    pid_t pid;

    pid = fork();

    if (pid < 0) {
        perror("Erro ao criar o processo filho");
        return 1;
    }

    if (pid == 0) {
        printf("Eu sou o processo filho. Meu PID é %d e o PID do meu pai é %d\n", getpid(), getppid());
    } else {
        printf("Eu sou o processo pai. Meu PID é %d e o PID do meu filho é %d\n", getpid(), pid);
    }

    return 0;
}
