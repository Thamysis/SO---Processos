#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>  
#include <string.h> 

int main() {
    int fd;

    fd = open("exemplo2.txt", O_RDONLY);
    if (fd == -1) {
        perror("Erro ao abrir exemplo2.txt, criando um novo arquivo examplo_criado.txt");

        fd = open(" exemplo_criado.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
        if (fd == -1) {
            perror("Erro ao criar o arquivo  exemplo_criado.txt");
            return 1;
        }

        const char *message = "Este arquivo foi criado porque exemplo2.txt não existia.\n";
        write(fd, message, sizeof(char) * strlen(message));
        printf("Arquivo  exemplo_criado.txt foi criado e a mensagem foi escrita nele.\n");

        close(fd);
    } else {
        printf("Arquivo exemplo2.txt aberto com sucesso.\n");
        close(fd);
    }

    return 0;
}
