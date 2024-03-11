#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main(void) {

	int numbs[100];
	int end = 0;
	int i = 0;
	scanf("%d\n", numbs + i);
	while (numbs[i] != 42) {
		i++;
		scanf("%d\n", numbs + i);
		end = i;
	}

	for (i = 1; i < end + 1; i++)
	{
		printf("%d\n", numbs[i - 1]);
	}


	return 0;
}