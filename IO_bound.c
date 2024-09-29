#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define BUFFER_SIZE 4096

int main() {
    char buffer[BUFFER_SIZE];
    long long total_bytes = 0;
    
    printf("Aperte Ctrl+C para parar.\n");
    
    while (1) {
        FILE *input = fopen("/dev/urandom", "rb");
        FILE *output = fopen("/dev/null", "wb");
        
        if (input == NULL || output == NULL) {
            perror("Error opening files");
            exit(1);
        }
        
        size_t bytes_read;
        while ((bytes_read = fread(buffer, 1, BUFFER_SIZE, input)) > 0) {
            fwrite(buffer, 1, bytes_read, output);
            total_bytes += bytes_read;
            
            if (total_bytes % (1024 * 1024) == 0) {  // Checar a cada 1mb
                printf("Processado %lld MB .\n", total_bytes / (1024 * 1024));
                fflush(stdout);  // Force output
                sleep(1);  // Sleep por 1 segundo para forçar uma mudança voluntária de contexto
            }
        }
        
        fclose(input);
        fclose(output);
    }
    
    return 0;
}
