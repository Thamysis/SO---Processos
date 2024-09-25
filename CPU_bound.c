#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int prime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0) return 0;
    }
    return 1;
}

int main() {
    long long count = 0;
    int num = 2;
    
    printf("Starting. Ctrl+c to stop\n");
    
    while (1) {
        if (prime(num)) {
            count++;
        }
        num++;
        
        if (count % 1000000 == 0) {
            printf("Found %lld prime numbers so far.\n", count);
        }
    }
    
    return 0;
}
