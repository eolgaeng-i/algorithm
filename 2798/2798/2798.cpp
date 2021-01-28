#include<stdio.h>

int main() {
	int N, M;
	int arr[100];
	int max = 0, sum = 0;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]);
	}

	for (int i = 0; i < N; i++) {
		for (int j = i+1; j < N; j++) {
			for (int k = j + 1; k < N; k++) {
				sum = arr[i] + arr[j] + arr[k];
				if (sum <= M) {
					if (sum > max) {
						max = sum;
					}
				}
			}
		}
	}

	printf("%d", max);
	return 0;
}