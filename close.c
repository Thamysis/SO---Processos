#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    char buffer[128];
    ssize_t bytesRead;

    fd = open("exemplo.txt", O_RDONLY);
    if (fd == -1) {
        perror("Erro ao abrir o arquivo example.txt");
        return 1;
    }

    printf("Arquivo example.txt aberto com sucesso.\n");

    bytesRead = read(fd, buffer, sizeof(buffer) - 1);
    if (bytesRead == -1) {
        perror("Erro ao ler o arquivo");
        close(fd); 
        return 1;
    }

    buffer[bytesRead] = '\0';
    printf("Conteúdo lido do arquivo:\n%s\n", buffer);

    if (close(fd) == -1) {
        perror("Erro ao fechar o arquivo");
        return 1;
    }

    printf("Arquivo examplo.txt foi fechado com sucesso.\n");

    return 0;
}
