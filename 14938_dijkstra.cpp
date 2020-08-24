// 200824 #14938 Gold III
// dijkstra
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
const int INF = 1000000007;
int item[101];
int d[101];
vector<pii> v[101];
int N, M, R;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M >> R;
	for (int i = 1; i <= N; i++)
		cin >> item[i];

	for (int i = 0; i < R; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		v[a].push_back({ cost, b });
		v[b].push_back({ cost, a });
	}
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		fill(d, d + N + 1, INF);
		d[i] = 0;
		pq.push({ 0, i });
		while (!pq.empty()) {
			int cur = pq.top().second;
			int cost = pq.top().first;
			pq.pop();
			if (d[cur] < cost)
				continue;
			for (auto i : v[cur]) {
				int next = i.second;
				int nCost = cost + i.first;
				if (nCost < d[next]) {
					d[next] = nCost;
					pq.push({ nCost, next });
				}
			}
		}
		// 시작점에 따라 가장 큰 것을 ans로
		// 어차피 중복방문하면 아이템은 사라지니까
		// 방문만 할 수 있으면 sum+=item[i]
		for (int i = 1; i <= N; i++) {
			if (d[i] <= M)
				sum += item[i];
		}
		ans = max(ans, sum);
	}
	cout << ans;
}