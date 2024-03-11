#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int isPrime(int num) {
    if (num < 2) {
        return 0;
    }
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return 0;
        }
    }
    return 1;
}

void generatePrimes(int m, int n) {
    for (int num = m; num <= n; num++) {
        if (isPrime(num)) {
            printf("%d\n", num);
        }
    }
}

int main() {
    int t;
    scanf("%d", &t);

    for (int i = 0; i < t; i++) {
        int m, n;
        scanf("%d %d", &m, &n);

        generatePrimes(m, n);

        printf("\n");
    }

    return 0;
}