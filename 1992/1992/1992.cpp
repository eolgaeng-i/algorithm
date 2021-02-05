#include<stdio.h>
#include<stdlib.h>


void check(char **arr, int rs, int rf, int cs, int cf, int N) {
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
	printf("%c", arr[rs][cs]);
	return;
}

/*void check(char **arr, int rs, int rf, int cs, int cf, int N) {
	bool flag = false;
	for (int i = rs; i < rf; i++) {
		for (int j = cs; j < cf; j++) {
			//printf("%c", arr[i][j]);
			if (arr[i][j] != arr[rs][cs]) {
				flag = true;
			}
		}
		//printf("\n");
	}

	//printf("\n");
	if(flag == false) printf("%c", arr[rs][cs]);

	if (flag == true) {
		printf("(");
		check(arr, rs, rs + N / 2, cs, cs + N / 2, N / 2);
		check(arr, rs, rs + N / 2, cs + N / 2, cf, N / 2);
		check(arr, rs + N / 2, rf, cs,  cs + N / 2, N / 2);
		check(arr, rs + N / 2, rf, cs + N / 2, cf, N / 2);
		printf(")");
	}
	return;
}
*/
int main() {
	int N;
	char **arr;
	char temp[64];

	scanf("%d", &N);
	arr = (char **)malloc(sizeof(char*)* N);
	for (int i = 0; i < N; i++) {
		arr[i] = (char *)malloc(sizeof(char)*N);
		scanf("%s", &temp);
		for (int j = 0; j < N; j++) {
			arr[i][j] = temp[j];
		}
	}

	check(arr, 0, N, 0, N, N);
	return 0;
}