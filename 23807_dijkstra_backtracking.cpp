// 211217 #23807 두단계 최단경로3 Gold III
// backtracking + dijkstra
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
typedef pair<ll, pl> pll;
const int MAX = 100011;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e16;
const int MOD = 1e9 + 7;
int N, M, X, Z, P;
ll d[101][MAX], ans = LNF;
vector<pl> v[MAX];
vector<int> p;
bool vis[MAX];
void preDijkstra(int s) {
	priority_queue<pl, vector<pl>, greater<pl>> pq;
	for (int i = 0; i <= N; i++) {
		d[s][i] = LNF;
	}
	d[s][p[s]] = 0;
	pq.push({ 0,p[s] });
	while (!pq.empty()) {
		int cur = pq.top().second;
		ll cost = pq.top().first;
		pq.pop();
		if (d[s][cur] < cost)
			continue;
		for (auto i : v[cur]) {
			int next = i.second;
			ll nCost = cost + i.first;
			if (nCost < d[s][next]) {
				d[s][next] = nCost;
				pq.push({ nCost,next });
			}
		}
	}
}
void solve(int cur, int cnt, ll dis) {
	if (cnt >= 3) {
		ll dist = d[cur][Z];
		ans = min(ans, dis+dist);
		return;
	}
	for (int i = 0; i < p.size(); i++) {
		if (!vis[i]) {
			vis[i] = true;
			ll dist = 0;
			if (cnt == 0)
				dist = d[i][X];
			else
				dist = d[cur][p[i]];
			solve(i, cnt + 1, dis + dist);
			vis[i] = false;
		}
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	while (M--) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ 1LL * c, b });
		v[b].push_back({ 1LL * c,a });
	}
	cin >> X >> Z >> P;
	while (P--) {
		int y;
		cin >> y;
		p.push_back(y);
	}
	for (int i = 0; i < p.size(); i++) {
		preDijkstra(i);
	}
	solve(-1, 0, 0);
	if (ans >= LNF)
		cout << -1;
	else cout << ans;
}