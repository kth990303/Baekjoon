// 210921 #1396 크루스칼의공 Platinum I
// LCA + MST
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
typedef pair<int, pi> pii;
const int SIZE = 18;
const int MAX = 200003;
const int INF = 0x3f3f3f3f; 
int N, M, Q, d[MAX], p[MAX][SIZE + 1], par[MAX], sz[MAX], T[MAX];
vector<int> v[MAX];
vector<pii> e;
void init(int cur) {
	for (auto i : v[cur]) {
		if (d[i] == -1) {
			d[i] = d[cur] + 1;
			p[i][0] = cur;
			init(i);
		}
	}
}
int lca(int a, int b) {
	if (d[a] < d[b])
		swap(a, b);
	int diff = d[a] - d[b];
	int j = 0;
	while (diff) {
		if (diff % 2)
			a = p[a][j];
		diff /= 2;
		j++;
	}
	if (a == b)
		return a;
	for (int j = SIZE; j >= 0; j--) {
		if (p[a][j] != -1 && p[a][j] != p[b][j]) {
			a = p[a][j];
			b = p[b][j];
		}
	}
	a = p[a][0];
	return a;
}
int find(int a) {
	if (a == par[a])
		return a;
	return par[a] = find(par[a]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return false;
	par[b] = a;
	return true;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 1; i <= N + M; i++) {
		par[i] = i;
		sz[i] = 1;
	}
	for (int i = 0; i < M; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		e.push_back({ cost, {a,b} });
	}
	sort(all(e));
	for (int i = 0; i < e.size(); i++) {
		int n1 = e[i].second.first;
		int n2 = e[i].second.second;
		int cost = e[i].first;
		int idx = N + i + 1;
		n1 = find(n1);
		n2 = find(n2);
		if (n1 != n2) {
			sz[idx] = sz[n1] + sz[n2];
			T[idx] = cost;
			v[idx].push_back(n1);
			v[idx].push_back(n2);
			merge(idx, n1);
			merge(idx, n2);
		}
	}
	memset(p, -1, sizeof(p));
	fill(d, d + MAX, -1);
	for (int i = N + M; i >= 1; i--) {
		if (d[i] == -1) {
			d[i] = 0;
			init(i);
		}
	}
	for (int j = 0; j < SIZE; j++) {
		for (int i = 1; i <= N + M; i++) {
			if (p[i][j] != -1)
				p[i][j + 1] = p[p[i][j]][j];
		}
	}
	cin >> Q;
	while (Q--) {
		int a, b;
		cin >> a >> b;
		if (find(a) != find(b))
			cout << -1 << "\n";
		else {
			int n = lca(a, b);
			cout << T[n] << " " << sz[n] << "\n";
		}
	}
}