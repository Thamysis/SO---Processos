#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <unistd.h>
#include <time.h>

int primo(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    long long count = 0;
    int num = 2;
    time_t start_time = time(NULL);
   
    printf("Aperte Ctrl+C para parar.\n");
   
    while (1) {
        for (int i = 0; i < 1000000; i++) {
            if (primo(num)) {
                count++;
            }
            num++;
        }
       
        printf("Found %lld prime numbers so far.\n", count);
        fflush(stdout);  
       
 
        if (time(NULL) - start_time >= 5) {
            printf("Sleeping for 100ms...\n");
            usleep(100000);  // Sleep por 100ms
            start_time = time(NULL);
        }
    }
   
    return 0;
}
