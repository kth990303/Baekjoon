// 210406 #20040 사이클 게임 Gold IV
// union-find
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 500001;
int N, M, p[MAX];
int find(int a) {
	if (a == p[a])
		return a;
	return p[a] = find(p[a]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return false;
	p[b] = a;
	return true;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		p[i] = i;
	}
	for (int i = 1; i <= M; i++) {
		int a, b;
		cin >> a >> b;
		// 이미 같은 집합인데 또 연결해버리면 사이클 생성
		if (find(a) == find(b)) {
			cout << i << "\n";
			return 0;
		}
		merge(a, b);
	}
	cout << 0 << "\n";
}