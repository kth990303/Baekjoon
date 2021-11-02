// 210113 #6118 ¼û¹Ù²ÀÁú Silver I
// bfs (E dis: 1) or dijkstra
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 20001;
int N, M, maxD;
vector<int> v[MAX], ans;
bool visit[MAX];
void bfs(int cur, int dis) {
	queue<pair<int, int>> q;
	q.push({ cur, dis });
	visit[cur] = true;
	while (!q.empty()) {
		int node = q.front().first;
		int d = q.front().second;
		if (d > maxD) {
			maxD = d;
			ans.clear();
		}
		if (d == maxD)
			ans.push_back(node);
		q.pop();
		for (auto i : v[node]) {
			if (!visit[i]) {
				visit[i] = true;
				q.push({ i, d + 1 });
			}
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	bfs(1, 0);
	sort(ans.begin(), ans.end());
	cout << ans[0] << " " << maxD << " " << ans.size() << "\n";
}