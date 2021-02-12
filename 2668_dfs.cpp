// 210212 #2668 숫자고르기 Gold V
// if cycle and this cur is myself,
// than same set
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 101;
int N, a[MAX];
bool visit[MAX];
vector<int> v;
void dfs(int cur, int k) {
	if (visit[cur]) {
		if (cur == k)
			v.push_back(cur);
		return;
	}
	visit[cur] = true;
	dfs(a[cur], k);
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= N; i++) {
		dfs(i, i);
		fill(visit, visit + MAX, false);
	}
	cout << v.size() << "\n";
	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << "\n";
	}
}