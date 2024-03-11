#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int prior(char c) {
    if (c == '^')
        return 3;
    if (c == '*' || c == '/')
        return 2;
    if (c == '+' || c == '-')
        return 1;
    else return -1;
}

void polish(char* expr, char* result) {
    char stack[400];
    int ptr = -1;
    int j = 0;

    for (int i = 0; expr[i]; ++i) {

        if (isalpha(expr[i]))
            result[j++] = expr[i];

        else if (expr[i] == '(') 
            stack[++ptr] = '(';

        else if (expr[i] == ')') {
            while (stack[ptr] != '(')
                result[j++] = stack[ptr--];

            ptr--;
        }
        else {
            while (prior(expr[i]) <= prior(stack[ptr])){
                result[j++] = stack[ptr--];
            }
            stack[++ptr] = expr[i];
        }
    }

    while (ptr != -1)
        result[j++] = stack[ptr--];

    result[j] = '\0';
}

int main() {
    int t;
    scanf("%d", &t);


    while (t) {
        char expr[400];
        char result[400];
        scanf("%s", expr);

        polish(expr, result);

        printf("%s\n", result);
        t--;
    }

    return 0;
}