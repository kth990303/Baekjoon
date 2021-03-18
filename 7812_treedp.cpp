// 210318 #7812 Áß¾Ó Æ®¸® Platinum IV
// fun tree_dp + dfs
// Good dfs question. later, i should solve again 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 10001;
typedef long long ll;
const ll INF = 1e18;
ll N, dis[MAX], a[MAX], ans = INF;
vector<pair<ll, ll>> v[MAX];
// dfs init distance
ll dfs(ll cur, ll prev) {
	a[cur] = 1;
	dis[cur] = 0;
	for (auto i : v[cur]) {
		if (i.second != prev) {
			dis[cur] += dfs(i.second, cur) + i.first * a[i.second];
			// all dfs done, a[cur] init done
			a[cur] += a[i.second];
		}
	}
	return dis[cur];
}
void dp(ll cur, ll prev) {
	for (auto i : v[cur]) {
		if (i.second != prev) {
			// No subtree's cost -> not search these costs
			// subtree's cost -> search these costs
			// -> N-a[i.second] - a[i.second]
			dis[i.second] = dis[cur] - a[i.second] * i.first
				+ (N - a[i.second]) * i.first;
			dp(i.second, cur);
		}
	}
	// update answer
	ans = min(ans, dis[cur]);
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	while (1) {
		fill(dis, dis + MAX, 0);
		fill(a, a + MAX, 0);
		for (auto& i : v) {
			i.clear();
		}
		ans = INF;
		cin >> N;
		if (!N) break;
		for (int i = 0; i < N - 1; i++) {
			ll a, b, cost;
			cin >> a >> b >> cost;
			v[a].push_back({ cost, b });
			v[b].push_back({ cost, a });
		}
		dfs(0, -1);
		dp(0, -1);
		cout << ans << "\n";
	}
}