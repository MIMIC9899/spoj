#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int multiply(int x, int res[], int res_size) {
    int over = 0; 

    for (int i = 0; i < res_size; i++) {
        int numb = res[i] * x + over;
        res[i] = numb % 10;
        over = numb / 10; 
    }

    while (over) {
        res[res_size] = over % 10;
        over = over / 10;
        res_size++;
    }
    return res_size;
}

void factorial(int n) {
    int res[500];
    res[0] = 1;
    int res_size = 1;

    for (int x = 2; x <= n; x++) {
        res_size = multiply(x, res, res_size);
    }

    for (int i = res_size - 1; i >= 0; i--) {
        printf("%d", res[i]);
    }
    printf("\n");
}

int main() {
    int n, len;
    scanf("%d", &len);
    for (int i = 0; i < len; i++)
    {
        scanf("%d", &n);
        factorial(n);
    }
    return 0;
}