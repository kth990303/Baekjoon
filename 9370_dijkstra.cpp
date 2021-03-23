// 210323 #9370 미확인 도착지 Gold II
// dijkstra 1. O(5MlgN): 636ms 2. O(MlgN): 132ms
// solution 2: input *2, if G~H : input*2-1
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 2001;
const int INF = 1e9 + 7;
int N, M, T, S, G, H, d[MAX];
typedef pair<int, int> pi;
vector<pi> v[MAX];
bool visit[MAX][MAX];
int solve(int s, int e) {
	fill(d, d + MAX, INF / 2 * 2);
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	d[s] = 0;
	pq.push({ 0, s });
	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (d[cur] < cost)
			continue;
		for (auto i : v[cur]) {
			int nCost = i.first + cost;
			int next = i.second;
			if (nCost < d[next]) {
				d[next] = nCost;
				pq.push({ nCost, next });
			}
		}
	}
	return d[e];
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		memset(visit, false, sizeof(visit));
		for (auto& i : v) {
			i.clear();
		}
		cin >> N >> M >> T >> S >> G >> H;
		for (int i = 0; i < M; i++) {
			int a, b, cost;
			cin >> a >> b >> cost;
			if (a == G && b == H || a == H && b == G) {
				v[a].push_back({ cost * 2 - 1, b });
				v[b].push_back({ cost * 2 - 1, a });
			}
			else {
				v[a].push_back({ cost * 2, b });
				v[b].push_back({ cost * 2, a });
			}
		}
		vector<int> ans;
		for (int i = 0; i < T; i++) {
			int e;
			cin >> e;
			int dis = solve(S, e);
			if (dis % 2)
				ans.push_back(e);
		}
		sort(ans.begin(), ans.end());
		for (auto i : ans) {
			cout << i << " ";
		}
		cout << "\n";
	}
}