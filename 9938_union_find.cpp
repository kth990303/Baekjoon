// 210325 #9938 ¹æ Ã»¼Ò Platinum III
// union-find, merge order important
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int MAX = 300001;
const int INF = 1e9 + 7;
int N, L, p[MAX];
bool visit[MAX];
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

	cin >> N >> L;
	for (int i = 1; i <= L; i++) {
		p[i] = i;
	}
	for (int i = 1; i <= N; i++) {
		int a, b;
		cin >> a >> b;
		if (!visit[a]) {
			visit[a] = true;
			cout << "LADICA\n";
			merge(b, a);
		}
		else if (!visit[b]) {
			visit[b] = true;
			cout << "LADICA\n";
			merge(a, b);
		}
		else if (!visit[find(a)]) {
			visit[find(a)] = true;
			cout << "LADICA\n";
			merge(b, find(a));
		}
		else if (!visit[find(b)]) {
			visit[find(b)] = true;
			cout << "LADICA\n";
			merge(a, find(b));
		}
		else
			cout << "SMECE\n";
	}
}