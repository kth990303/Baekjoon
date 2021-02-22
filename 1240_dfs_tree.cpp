// 210223 #1240 노드사이의 거리 Gold IV
// DFS + tree
// I think it's Gold V
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 1001;
int N, M;
vector<pair<int, int>> v[MAX];
bool visit[MAX];
int dfs(int cur, int des, int cost) {
	if (cur == des)
		return cost;
	visit[cur] = true;
	for (auto i : v[cur]) {
		if (!visit[i.first]) {
			int ret = dfs(i.first, des, cost + i.second);
			if (ret != -1)
				return ret;
		}
	}
	return -1;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N - 1; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		v[a].push_back({ b, cost });
		v[b].push_back({ a, cost });
	}
	for (int i = 0; i < M; i++) {
		fill(visit, visit + MAX, false);
		int a, b;
		cin >> a >> b;
		cout << dfs(a, b, 0) << "\n";
	}
}