#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(char* a, char* b) {
	char tmp = *b;
	*b = *a;
	*a = tmp;
}

void reserve(int m, int n) {
	char strm[100];
	char strn[100]; 
	sprintf(strm, "%d", m);
	sprintf(strn, "%d", n);

	int lenm = strlen(strm);

	for (int k = lenm - 1, j = 0; k > j; k--, j++)
		swap(&strm[k], &strm[j]);

	int lenn = strlen(strn);

	for (int k = lenn - 1, j = 0; k > j; k--, j++)
		swap(&strn[k], &strn[j]);

	m = strtol(strm, NULL, 10);
	n = strtol(strn, NULL, 10);

	int sum = n + m;

	sprintf(strm, "%d", sum);

	lenm = strlen(strm);

	for (int k = lenm - 1, j = 0; k > j; k--, j++)
		swap(&strm[k], &strm[j]);

	int flag = 0;
	for (int i = 0; i < lenm; i++)
	{
		if (flag == 0 && strm[i] == '0');
		else
			flag = 1;
		if (flag == 1)
		{
			putchar(strm[i]);
		}
	}
	printf("\n");
}

int main(void) {

	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		int m, n;
		scanf("%d %d", &m, &n);

		reserve(m, n);

		//printf("%d\n", res);
	}

	return 0;
}