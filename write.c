#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    ssize_t bytesWritten;
    const char *message = "Esta é uma mensagem escrita usando a chamada ao sistema write.\n";

    fd = open("exemplo.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd == -1) {
        perror("Erro ao abrir/criar o arquivo");
        return 1;
    }

    bytesWritten = write(fd, message, sizeof(char) * strlen(message));
    if (bytesWritten == -1) {
        perror("Erro ao escrever no arquivo");
        close(fd);
        return 1;
    }

    printf("Mensagem escrita com sucesso no arquivo 'exemplo.txt'.\n");

    close(fd);
    return 0;
}
