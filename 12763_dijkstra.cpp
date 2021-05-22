// 210523 #12763 지각하면 안돼 Gold II
// dijkstra two_dimension (like KCM travel)
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
typedef pair<pair<int, int>, int> pi;
typedef long long ll;
const int MAX = 101;
const int INF = 0x3f3f3f3f;
int N, T, M, L, d[MAX][10001];
vector<pi> v[MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> T >> M >> L;
	while (L--) {
		int a, b, t, c;
		cin >> a >> b >> t >> c;
		v[a].push_back({ {t, b}, c });
		v[b].push_back({ {t, a}, c });
	}
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	memset(d, INF, sizeof(d));
	pq.push({ {0, 1}, 0 });
	d[1][0] = 0;
	while (!pq.empty()) {
		int time = pq.top().first.first;
		int cur = pq.top().first.second;
		int cost = pq.top().second;
		pq.pop();
		if (time > T || d[cur][time] < cost)
			continue;
		for (auto i : v[cur]) {
			int nTime = i.first.first + time;
			int nCost = i.second + cost;
			int next = i.first.second;
			if (nTime <= T && nCost < d[next][nTime]) {
				for (int j = nTime + 1; j <= T; j++) {
					if (d[next][j] <= nCost)
						break;
					d[next][j] = nCost;
				}
				d[next][nTime] = nCost;
				pq.push({ {nTime, next}, nCost });
			}
		}
	}
	int ans = INF;
	for (int i = 0; i <= T; i++) {
		ans = min(ans, d[N][i]);
	}
	if (ans > M)
		cout << "-1\n";
	else
		cout << ans << "\n";

}