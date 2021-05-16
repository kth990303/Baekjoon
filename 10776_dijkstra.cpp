// 210516 #10776 Á¦±¹ Platinum V
// I think it's Gold I. because it's same as KCM Travel
// dijkstra + dp
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#include <cstring>
using namespace std;
typedef pair<pair<int, int>, int> pi;
const int MAX = 2001;
const int MAXC = 201;
const int INF = 0x3f3f3f3f;
int N, M, K, A, B, d[MAX][MAXC], ans = INF;
vector<pi> v[MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> K >> N >> M;
	for (int i = 0; i < M; i++) {
		int s, e, t, h;
		cin >> s >> e >> t >> h;
		v[s].push_back({ {t, e}, h});
		v[e].push_back({ {t, s}, h });
	}
	cin >> A >> B;
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	pq.push({ {0, A}, 0 });
	memset(d, INF, sizeof(d));
	d[A][0] = 0;
	while (!pq.empty()) {
		int time = pq.top().first.first;
		int cur = pq.top().first.second;
		int h = pq.top().second;
		pq.pop();
		if (cur == B) {
			ans = time;
			break;
		}
		if (h >= K || d[cur][h] < time)
			continue;
		for (auto i : v[cur]) {
			int nTime = i.first.first + time;
			int nH = i.second + h;
			int next = i.first.second;
			if (nH < K && nTime < d[next][nH]) {
				// use dp
				for (int j = nH + 1; j <= K; j++) {
					if (d[next][j] <= nTime)
						break;
					d[next][j] = nTime;
				}
				d[next][nH] = nTime;
				pq.push({ {nTime, next}, nH });
			}
		}
	}
	if (ans >= INF)
		cout << "-1\n";
	else
		cout << ans << "\n";
}