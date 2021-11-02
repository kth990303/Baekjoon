// 210419 #1486 µî»ê Gold I
// dijkstra
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
using namespace std;
typedef pair<int, int> pi;
const int MAX = 25;
const int INF = 1e9 + 7;
int N, M, T, D, a[MAX][MAX], d[625];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int dijkstra(int s, int e) {
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	fill(d, d + 625, INF);
	d[s] = 1;
	pq.push({ 0, s });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int y = cur / MAX;
		int x = cur % MAX;
		int cost = pq.top().first;
		pq.pop();
		if (d[cur] < cost)
			continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
				if (abs(a[ny][nx] - a[y][x]) > T)
					continue;
				int next = ny * MAX + nx;
				int nCost = cost;
				if (a[ny][nx] > a[y][x]) {
					nCost += (a[ny][nx] - a[y][x]) * (a[ny][nx] - a[y][x]);
				}
				else
					nCost += 1;
				if (nCost < d[next]) {
					d[next] = nCost;
					pq.push({ nCost, next });
				}
			}
		}
	}
	return d[e];
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M >> T >> D;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			if (s[j] >= 'A' && s[j] <= 'Z')
				a[i][j] = s[j] - 'A';
			else
				a[i][j] = s[j] - 'a' + 26;
		}
	}
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (a[i][j] <= ans)
				continue;
			int s = 0;
			int e = i * MAX + j;
			if (dijkstra(s, e) + dijkstra(e, s) <= D)
				ans = max(ans, a[i][j]);
		}
	}
	cout << ans << "\n";
}