// 210423 #14461 소가 길을 건너간 이유 7 Gold I
// dijkstra
// No DP! (because of cycle)
// use visit array (because of cycle)
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <cmath>
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef pair<pair<int, int>, int> pi;
const int INF = 1e9 + 7;
const int MAX = 101;
int a[MAX][MAX], N, T, ans, d[10001];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
bool visit[MAX][MAX][3];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
			d[i * N + j] = INF;
		}
	}
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	d[0] = 0;
	pq.push({ { 0, 0 }, 0 });
	while (!pq.empty()) {
		int idx = pq.top().first.second;
		int cur = pq.top().second;
		int y = cur / N;
		int x = cur % N;
		int cost = pq.top().first.first;
		pq.pop();
		if (visit[y][x][idx % 3])
			continue;
		visit[y][x][idx % 3] = true;
		d[cur] = min(d[cur], cost);
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
				int next = ny * N + nx;
				int nCost = cost + T;
				if (idx % 3 == 2)
					nCost += a[ny][nx];
				pq.push({ {nCost, idx + 1}, next });
			}
		}
	}
	cout << d[N * N - 1] << "\n";
}