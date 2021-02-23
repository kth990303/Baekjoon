// 210223 #20925 maplestory Gold II
// greedy? No! high exp but high cost, no answer.
// so dynamic programming (two parameters dp)
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAX = 201;
const int MAX_T = 1001;
const ll INF = 1e18;
ll N, T, d[MAX][MAX_T], cost[MAX][MAX];
vector<pair<ll, ll>> v;
// d[cur][time]: cur'th ground exp until the time 
ll dp(int cur, int time) {
	ll& ret = d[cur][time];
	if (ret != -1)
		return ret;
	// exist initial condition
	// if cannot first comming ground
	// return -INF
	if (!time) {
		if (!v[cur].first)
			return ret = 0;
		else
			return ret = -INF;
	}
	ret = dp(cur, time - 1) + (ll)v[cur].second;
	for (int i = 0; i < N; i++) {
		if (cur != i && time - cost[cur][i] > 0) {
			// if i>cur and can afford cost[i][cur] (cost[cur][i])
			// then, tmp !~ -INF
			ll tmp = dp(i, time - cost[cur][i]);
			if (tmp >= v[cur].first)
				ret = max(ret, tmp);
		}
	}
	return ret;
}
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
	memset(d, -1, sizeof(d));
	for (int i = 0; i < N; i++) {
		ans = max(ans, dp(i, T));
	}
	cout << ans << "\n";
}