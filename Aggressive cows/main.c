#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int compare(const void* x1, const void* x2)   // функция сравнения элементов массива
{
	return (*(int*)x1 - *(int*)x2);              // если результат вычитания равен 0, то числа равны, < 0: x1 < x2; > 0: x1 > x2
}

int check(int N, int C, int mid, int* stalls) {
	int cows = 1, pos = stalls[0];
	for (int i = 1; i < N; i++) {
		if (stalls[i]-pos >= mid) {
			pos = stalls[i];
			cows++;
			if (cows == C) 
				return 1;
		}
	}

	return 0;
}

int findDistance(int N, int C, int* stalls) {
	qsort(stalls, N, sizeof(int), compare);
	int start = 0, end = stalls[N - 1], max = 0;
	while (start < end) {
		int mid = (start + end) / 2;
		if (check(N, C, mid, stalls)) {
			if (mid > max) 
				max = mid;
			start = mid + 1;
		}
		else 
			end = mid;
	}

	return max;
}

int main(void) {

	int nTest, N, C;
	long long stalls[1000];
	scanf("%d", &nTest);
	while (nTest--) {
		scanf("%d%d", &N, &C);
		for (int j = 0; j < N; j++)
			scanf("%lld", stalls + j);

		int k = findDistance(N, C, stalls);

		printf("%d\n", k);

	}

	return 0;
}