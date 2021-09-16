// 210916 #20010 ¾Ç´ö ¿µÁÖ ÇýÀ¯ Gold I
// I think it's Gold III
// mst + tree's diameter
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
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MAX = 1001;
const int MOD = 1e9 + 7;
ll N, K, ans1, ans2;
int p[MAX], node;
vector<pll> v;
vector<pl> c[MAX];
bool visit[MAX];
int find(int a) {
	if (a == p[a])
		return a;
	return p[a] = find(p[a]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return false;
	if (a > b)
		swap(a, b);
	p[b] = a;
	return true;
}
void dfs(int cur, ll n) {
	visit[cur] = true;
	if (ans2 < n) {
		ans2 = n;
		node = cur;
	}
	for (auto i : c[cur]) {
		if (!visit[i.second]) {
			dfs(i.second, n + i.first);
		}
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> K;
	for (int i = 0; i < N; i++)
		p[i] = i;
	for (int i = 0; i < K; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		v.push_back({ cost, {a,b} });
	}
	sort(all(v));
	for (int i = 0; i < K; i++) {
		int n1 = v[i].second.first;
		int n2 = v[i].second.second;
		ll cost = v[i].first;
		if (find(n1) != find(n2)) {
			ans1 += cost;
			merge(n1, n2);
			c[n1].push_back({ cost, n2 });
			c[n2].push_back({ cost, n1 });
		}
	}
	dfs(0, 0);
	ans2 = 0;
	memset(visit, false, sizeof(visit));
	dfs(node, 0);
	cout << ans1 << "\n" << ans2 << "\n";
}