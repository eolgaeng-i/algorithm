#include<stdio.h>
#include<stdlib.h>

void check(int **arr, int rs, int rf, int cs, int cf, int N) {
	for (int i = rs; i < rf; i++) {
		for (int j = cs; j < cf; j++) {
			if (arr[i][j] != arr[rs][cs]) {
				printf("(");
				check(arr, rs, rs + N / 2, cs, cs + N / 2, N / 2);
				check(arr, rs, rs + N / 2, cs + N / 2, cf, N / 2);
				check(arr, rs + N / 2, rf, cs, cs + N / 2, N / 2);
				check(arr, rs + N / 2, rf, cs + N / 2, cf, N / 2);
				printf(")");
				return;
			}
		}
	}
	printf("%d", arr[rs][cs]);
	return;
}

/*void check(int **arr, int rs, int rf, int cs, int cf, int N) {
	bool flag = false;
	for (int i = rs; i < rf; i++) {
		for (int j = cs; j < cf; j++) {
			if (arr[i][j] != arr[rs][cs]) {
				flag = true;
			}
		}
	}
	if(flag == false) printf("%d", arr[rs][cs]);

	if (flag == true) {
		printf("(");
		check(arr, rs, rs + N / 2, cs, cs + N / 2, N / 2);
		check(arr, rs, rs + N / 2, cs + N / 2, cf, N / 2);
		check(arr, rs + N / 2, rf, cs,  cs + N / 2, N / 2);
		check(arr, rs + N / 2, rf, cs + N / 2, cf, N / 2);
		printf(")");
	}
	return;
}*/

int main() {
	int N;
	int **arr;
	int temp;

	scanf("%d", &N);
	arr = (int **)malloc(sizeof(int*)* N);
	for (int i = 0; i < N; i++) {
		arr[i] = (int *)malloc(sizeof(int)*N);
		scanf("%d", &temp);
		for (int j = 1; j <= N; j++) {
			arr[i][N - j] = temp % 10;
			temp /= 10;
		}
	}

	printf("\n");
	check(arr, 0, N, 0, N, N);
}