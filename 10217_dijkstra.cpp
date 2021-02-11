// 210211 #10217 KCM Travel Gold I
// dijkstra + dp
// because cost and time (two conditions)
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
const int MAX = 101;
const int MAXC = 10001;
const int INF = 1e9 + 7;
typedef pair<pair<int, int>, int> pii;
int N, M, K, d[MAX][MAXC];	// cost memoization
vector<pii> v[MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		cin >> N >> M >> K;
		for (auto& i : v) {
			i.clear();
		}
		for (int i = 0; i < K; i++) {
			int s, e, cost, time;
			cin >> s >> e >> cost >> time;
			v[s].push_back({ {time, e}, cost });
		}
		priority_queue<pii, vector<pii>, greater<pii>> pq;
		pq.push({ {0, 1}, 0 });
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAXC; j++) {
				d[i][j] = INF;
			}
		}
		d[1][0] = 0;
		while (!pq.empty()) {
			int time = pq.top().first.first;
			int cur = pq.top().first.second;
			int cost = pq.top().second;
			pq.pop();
			if (cost > M || d[cur][cost] < time)
				continue;
			for (auto i : v[cur]) {
				int nTime = i.first.first + time;
				int nCost = i.second + cost;
				int next = i.first.second;
				if (nCost <= M && nTime < d[next][nCost]) {
					// No -> 3120ms / Yes -> 260ms
					for (int j = nCost + 1; j <= M; j++) {
						if (d[next][j] <= nTime)
							break;
						d[next][j] = nTime;
					}
					d[next][nCost] = nTime;
					pq.push({ {nTime, next}, nCost });
				}
			}
		}
		int ans = INF;
		for (int i = 0; i <= M; i++) {
			ans = min(ans, d[N][i]);
		}
		if (ans >= INF)
			cout << "Poor KCM\n";
		else
			cout << ans << "\n";
	}
}