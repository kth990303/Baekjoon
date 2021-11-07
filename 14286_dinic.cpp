// 211107 #14286 간선끊어가기2 Platinum IV
// min_cut max_flow => dinic
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> pii;
const int MAX = 511;
const double INF = 0x3f3f3f3f;
const int LNF = 1e16;
const int MOD = 1e9 + 7;
int N, M, S, E, lv[MAX], w[MAX], ans;
struct Edge {
	int to, c, rev;
	Edge(int to, int c, int rev)
		:to(to), c(c), rev(rev) {}
};
vector<Edge> v[MAX];
void addEdge(int s, int e, int c) {
	v[s].emplace_back(e, c, v[e].size());
	v[e].emplace_back(s, 0, v[s].size() - 1);
}
bool bfs() {
	memset(lv, -1, sizeof(lv));
	lv[S] = 0;
	queue<int> q;
	q.push(S);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto i : v[cur]) {
			if (i.c && lv[i.to] == -1) {
				lv[i.to] = lv[cur] + 1;
				q.push(i.to);
			}
		}
	}
	return lv[E] != -1;
}
int dfs(int cur, int c) {
	if (cur == E)return c;
	for (; w[cur] < v[cur].size(); w[cur]++) {
		Edge& e = v[cur][w[cur]];
		if (!e.c || lv[e.to] != lv[cur] + 1)
			continue;
		int f = dfs(e.to, min(c, e.c));
		if (f > 0) {
			e.c -= f;
			v[e.to][e.rev].c += f;
			return f;
		}
	}
	return 0;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	while (M--) {
		int a, b, cost;
		cin >> a >> b >> cost;
		addEdge(a, b, cost);
		addEdge(b, a, cost);
	}
	cin >> S >> E;
	while (bfs()) {
		memset(w, 0, sizeof(w));
		while (1) {
			int c = dfs(S, INF);
			if (!c)break;
			ans += c;
		}
	}
	cout << ans << "\n";
}