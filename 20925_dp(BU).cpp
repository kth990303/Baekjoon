#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int MAX = 201;
const int MAX_T = 1001;
const ll INF = 1e18;
ll N, T, d[MAX][MAX_T], cost[MAX][MAX];
vector<pair<ll, ll>> v;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> T;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> cost[i][j];
		}
	}
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		if (v[i].first)
			d[i][0] = -INF;
	}
	// if i,t order change, wrong answer
	// because i, j dp table update, then other time i, j can change
	for (int t = 1; t <= T; t++) {
		for (int i = 0; i < N; i++) {
			d[i][t] = d[i][t - 1] + v[i].second;
			for (int j = 0; j < N; j++) {
				if (i != j && t - cost[i][j] >= 0) {
					if (d[j][t - cost[i][j]] >= v[i].first) {
						d[i][t] = max(d[i][t], d[j][t - cost[i][j]]);
					}
				}
			}
			ans = max(ans, d[i][t]);
		}
	}
	cout << ans << "\n";
}