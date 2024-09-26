#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    ssize_t bytesRead;
    char buffer[128];

    fd = open("exemplo.txt", O_RDONLY);
    if (fd == -1) {
        perror("Erro ao abrir o arquivo");
        return 1;
    }

    printf("Conteúdo do arquivo 'exemplo.txt':\n");

    while ((bytesRead = read(fd, buffer, sizeof(buffer) - 1)) > 0) {
        buffer[bytesRead] = '\0';
        printf("%s", buffer);
    }

    if (bytesRead == -1) {
        perror("Erro ao ler o arquivo");
        close(fd);
        return 1;
    }

    close(fd);
    return 0;
}
