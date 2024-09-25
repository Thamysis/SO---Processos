#include <unistd.h>
#include <stdio.h>

int main() {
    void *initial_brk = sbrk(0);
    printf("Endereço inicial do break: %p\n", initial_brk);

    if (brk(initial_brk + 4096) == -1) {
        perror("Erro ao expandir o heap");
        return 1;
    }

    void *new_brk = sbrk(0);
    printf("Endereço após expansão: %p\n", new_brk);

    if (brk(initial_brk) == -1) {
        perror("Erro ao reduzir o heap");
        return 1;
    }

    void *final_brk = sbrk(0);
    printf("Endereço após redução: %p\n", final_brk);

    return 0;
}
