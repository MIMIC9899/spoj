#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void count(long long f) {
	int c = 0;

	while (f >= 5) {
		f /= 5;
		c += f;
	}

	printf("%d\n", c);
}

int main(void) {
	long long arr;
	int n;
	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%lld", &arr);

		count(arr);
	}

	return 0;
}