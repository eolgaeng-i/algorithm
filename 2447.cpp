#include<stdio.h>
#include<stdlib.h>

char **arr;

int divide(int num) {
	if (num >= 3) divide(num / 3);
	else return num;
}

int main() {
	int N;

	scanf("%d", &N);
	arr = (char**)malloc(sizeof(char*)*N);
	for (int i = 0; i < N; i++) {
		arr[i] = (char *)malloc(sizeof(char*)*N);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int ti = divide(i);
			int tj = divide(j);
			if (ti % 3 == 1 && tj % 3 == 1) {
				arr[i][j] = ' ';
			}
			else arr[i][j] = '*';
		}
		printf("\n");
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			printf("%c", arr[i][j]);
		}
		printf("\n");
	}
	return 0;
}
