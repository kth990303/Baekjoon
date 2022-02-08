// 220208 #5719 거의최단경로 Platinum V
// dijkstra + trace (dfs / bfs skill)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
const int MAX = 511;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e16;
const int MOD = 1e9 + 7;
int N, M, S, D, d[MAX];
vector<pi> v[MAX];
vector<int> p[MAX];
bool vis[MAX][MAX];
int dijkstra(int s, int e, int flag) {
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	fill(d, d + MAX, INF);
	d[s] = 0;
	pq.push({ 0, s });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (d[cur] < cost)continue;
		for (auto i : v[cur]) {
			int next = i.second;
			int nCost = i.first + cost;
			if (!flag && nCost < d[next]) {
				d[next] = nCost;
				p[next].clear();
				p[next].push_back(cur);
				pq.push({ nCost, next });
			}
			else if (!flag && nCost == d[next]) {
				p[next].push_back(cur);
			}
			else if (flag && nCost < d[next]) {
				if (vis[cur][next])continue;
				d[next] = nCost;
				pq.push({ nCost, next });
			}
		}
	}
	return d[e];
}
void dfs(int cur) {
	for (int i : p[cur]) {
		if (vis[i][cur])continue;
		vis[i][cur] = true;
		dfs(i);
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	while (cin >> N >> M && N) {
		memset(vis, false, sizeof(vis));
		for (auto& i : p)
			i.clear();
		for (auto& i : v)
			i.clear();
		cin >> S >> D;
		for (int i = 0; i < M; i++) {
			int n1, n2, cost;
			cin >> n1 >> n2 >> cost;
			v[n1].push_back({ cost, n2 });
		}
		dijkstra(S, D, 0);
		dfs(D);
		int ans = dijkstra(S, D, 1);
		cout << (ans >= INF ? -1 : ans) << "\n";
	}
}