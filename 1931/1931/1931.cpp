#include<stdio.h>
#include<stdlib.h>
#include<algorithm>

int compare(void const *a, void const *b) {
	printf("%d %d\n", *((int*)a + 1), *((int*)b + 1));
	if (*((int*)a + 1) < *((int*)b + 1)) return -1;
	else if (*((int*)a + 1) < *((int*)b + 1)) return 1;
	else if (*(int*)a < *(int*)b) return -1;
	else if (*(int*)a > *(int*)b) return 1;
	else return 0;
}

int main() {
	int N = 0;
	int count = 1;
	int list[100000][2];

	scanf("%d", &N);
	struct arr *temp;

	for (int i = 0; i < N; i++) {
		scanf("%d %d", &list[i][0], &list[i][1]);
	}
	qsort(list, N, sizeof(int) * 2, compare);

	for (int i = 0; i < N; i++) {
		printf("%d %d\n", list[i][0], list[i][1]);
	}

	int finT = list[0][1];
	for (int i = 1; i < N; i++) {
		if (finT < list[i][0]) {
			count++;
			finT = list[i][1];
		}
	}

	printf("%d", count);

	return 0;
}