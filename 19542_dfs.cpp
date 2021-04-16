// 210416 #19542 전단지 돌리기 Gold IV
// dfs -> leaf node depth
// and dfs to return the answer
#include <iostream>
#include <vector>
#include <algorithm>
#define all(v) (v).begin(), (v).end()
using namespace std;
const int MAX = 100001;
vector<int> v[MAX];
int N, S, D, d[MAX];
bool visit[MAX];
int dfs(int cur) {
	visit[cur] = true;
	for (auto i : v[cur]) {
		if (!visit[i]) {
			visit[i] = true;
			d[cur] = max(d[cur], dfs(i) + 1);
		}
	}
	return d[cur];
}
int solve(int cur) {
	int ret = 0;
	visit[cur] = true;
	for (auto i : v[cur]) {
		if (!visit[i] && d[i] >= D) {
			visit[i] = true;
			ret += solve(i) + 1;
		}
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> S >> D;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	dfs(S);
	fill(visit, visit + MAX, false);
	cout << solve(S) * 2 << "\n";
}