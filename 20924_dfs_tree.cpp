// 210222 #20924 트리의 기둥과 가지 Gold V
// Do you know dfs?
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 200001;
int N, R, in[MAX], ans, center;
vector<pair<int, int>> v[MAX];
bool visit[MAX];
int dfs(int cur, int cost) {
	int ret = cost;
	if (cur && in[cur] != 2) {
		center = cur;
		return cost;
	}
	visit[cur] = true;
	for (auto i : v[cur]) {
		if (!visit[i.first]) {
			ret += dfs(i.first, i.second);
		}
	}
	return ret;
}
// important
int dfs2(int cur) {
	visit[cur] = true;
	int ret = 0;
	for (auto i : v[cur]) {
		if (!visit[i.first]) {
			// if you want to check length of max tree branch
			ret = max(ret, dfs2(i.first) + i.second);
		}
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> R;
	// indegree? no, it's UDAG (undirected..)
	// so check only degree
	v[0].push_back({ R, 0 });
	v[R].push_back({ 0, 0 });
	in[R]++;
	center = R;
	for (int i = 0; i < N - 1; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		v[a].push_back({ b, cost });
		v[b].push_back({ a, cost });
		in[a]++;
		in[b]++;
	}
	ans = dfs(0, 0);
	cout << ans << " " << dfs2(center) << "\n";
}