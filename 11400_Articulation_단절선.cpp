// 200903 #11400 단절선 Platinum V
// 단절점과 단절선 알고리즘
// 개념을 익혀두자 (Standard)
// O(V+E)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100001;
vector<int> v[MAX];
vector<pair<int, int>> ans;
int d[MAX];
int V, E, id;
int dfs(int x, int parent) {
	d[x] = ++id;
	int ret = d[x];
	// 단절선을 찾는 것이므로 단절점 알고리즘과는 달리
	// child(자식 노드) 개수 변수가 있을 리가 없음
	for (auto i : v[x]) {
		// 부모꺼는 아까 봄
		if (i == parent)
			continue;
		// 아직 방문하지 않았다면
		if (!d[i]) {
			// 자신의 노드에서 탐색 이전꺼를 볼 수 있는지
			int prev = dfs(i, x);
			// 볼 수 없다면 그 선은 단절선
			if (prev > d[x])
				ans.push_back({ min(x, i), max(x, i) });
			// 연결돼있는 경우 중 가장 작은 거
			ret = min(ret, prev);
		}
		// 방문을 했다면 가장 작은 경우 리턴
		else
			ret = min(ret, d[i]);
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= V; i++) {
		if (!d[i])
			dfs(i, 0);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (auto i : ans) {
		cout << i.first << " " << i.second << "\n";
	}
}