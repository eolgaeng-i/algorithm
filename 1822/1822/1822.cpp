#include<stdio.h>
#include<set>

using namespace std;
using std::set;

int main() {
	int N, M;
	set<int> A, B;
	int temp=0, count = 0;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		A.insert(temp);
	}
	for (int i = 0; i < M; i++) {
		scanf("%d", &temp);
		if (!B.count(temp) && A.count(temp)) count++;
		B.insert(temp);
	}
	printf("%d\n", N - count);
	set<int>::iterator iter;
	for (iter = A.begin(); iter != A.end(); iter++) {
		if (!B.count(*iter)) {
			printf("%d ", *iter);
		}
	}

	return 0;
}