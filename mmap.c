#include <stdio.h>
#include <stdlib.h>
#include <sys/mman.h>
#include <string.h>
#include <unistd.h>

int main() {
    size_t size = 4096;

    void *mapped_memory = mmap(NULL, size, PROT_READ | PROT_WRITE, MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    if (mapped_memory == MAP_FAILED) {
        perror("Erro ao mapear memória com mmap");
        return 1;
    }

    printf("Memória mapeada em: %p\n", mapped_memory);

    strcpy((char *)mapped_memory, "Olá, mmap! Esta é uma área de memória mapeada.");

    printf("Dados na memória mapeada: %s\n", (char *)mapped_memory);

    if (munmap(mapped_memory, size) == -1) {
        perror("Erro ao desmapear memória");
        return 1;
    }

    printf("Memória desmapeada com sucesso.\n");

    return 0;
}
