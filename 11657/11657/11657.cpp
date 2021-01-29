#include<stdio.h>
#include<algorithm>
#include<limits.h>

struct Edge{
	int start;
	int end;
	int cost;
};

int main() {
	int N, M;
	int check = 0;
	int vertex[501] = {0,};
	Edge *E;

	scanf("%d %d", &N, &M);
	E = (Edge *)malloc(sizeof(Edge) * (M + 1));
	for (int i = 0; i < M; i++) {
		scanf("%d %d %d", &E[i].start, &E[i].end, &E[i].cost);
	}
	for (int i = 2; i < N + 1; i++) {
		vertex[i] = INT_MAX;
	}
	vertex[1] = 0;
	for (int i = 0; i < N; i++) {
		if (i == (N - 1)) {
			check = -1;
			printf("-1\n");
			return 0;
		}
		check = 0;
		for (int j = 0; j < M; j++) {
			if (vertex[E[j].start] != INT_MAX && vertex[E[j].start] + E[j].cost < vertex[E[j].end]) {
				check = 1;
				vertex[E[j].end] = vertex[E[j].start] + E[j].cost;
			}
		}
		if (check == 0) break;
	}
	
	for (int i = 2; i < N + 1; i++) {
		if (vertex[i] == INT_MAX) {
			printf("-1");
		}
		else printf("%d\n", vertex[i]);
	}

	return 0;
}