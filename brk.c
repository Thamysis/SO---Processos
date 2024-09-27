#include <unistd.h>
#include <stdio.h>

int main() {
	void *initial_brk = sbrk(0);
	if (initial_brk == (void *) -1) {
		perror("Erro ao obter o endereço inicial do break");
		return 1;
	}
	printf("Endereço inicial do break: %p\n", initial_brk);

	// Expandindo o heap em 4096 bytes (4 KB)
	char *new_brk = (char *)initial_brk + 4096;
	if (brk(new_brk) == -1) {
		perror("Erro ao expandir o heap");
		return 1;
	}

	void *current_brk = sbrk(0);
	if (current_brk == (void *) -1) {
		perror("Erro ao obter o novo endereço do break");
		return 1;
	}
    
    printf("Endereço após expansão: %p\n", current_brk);

	if (current_brk != new_brk) {
		printf("O endereço após expansão não corresponde ao esperado.\n");
		return 1;
	}

	return 0;
}
