#include<iostream>
#include<map>
#include<set>
#include<utility>
#include<string>

using namespace std;
using std::map;
using std::set;

int main() {
	map<string, int> m;
	int N, M;
	string temp;
	int count = 0;

	scanf("%d %d", &N, &M);
	for (int i = 0; i < (N+M); i++) {
		cin >> temp;
		if (m.count(temp) == 0) {
			m[temp] = 1;
		}
		else {
			m[temp]++;
			count++;
		}
	}

	printf("%d\n", count);
	map<string, int>::iterator iter;
	for (iter = m.begin(); iter != m.end(); iter++) {
		if (iter->second == 2) {
			cout << iter->first << endl;
		}
			
	}

	return 0;
}