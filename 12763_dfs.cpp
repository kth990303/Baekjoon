// 210523 #12763 지각하면 안돼 Gold II
// dfs (visit two_memsion)
// dijkstra + dp: 8ms 
// dijkstra : 32ms
// dfs: 184ms
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
int N, T, M, L, ans = INF;
vector<pi> v[MAX];
bool visit[MAX][10001];
void dfs(int cur, int time, int cost) {
	visit[cur][0] = true;
	if (cur == N) {
		ans = min(ans, cost);
		return;
	}
	for (auto i : v[cur]) {
		int nTime = time + i.first.first;
		if (!visit[i.first.second][nTime]) {
			int next = i.first.second;
			int nCost = cost + i.second;
			if (nTime > T || nCost > M)
				continue;
			dfs(next, nTime, nCost);
		}
	}
}
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
	dfs(1, 0, 0);
	if (ans >= INF)
		cout << -1 << "\n";
	else
		cout << ans << "\n";
}