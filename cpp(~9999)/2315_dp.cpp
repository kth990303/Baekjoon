// 210809 #2315 °¡·Îµî ²ô±â Platinum III
// dp[s][e] because of no time turning on/off
// prefix_sum: before time? -> if memoization, no update
// prefix_sum: extra W -> update only s, e
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;
const int MAX = 1001;
const ll LNF = 1e18;
ll N, M, d[MAX][MAX][2], w[MAX];
vector<pl> v;
ll dp(int s, int e, int flag) {
	if (s == 1 && e == N)
		return 0;
	ll& ret = d[s][e][flag];
	if (ret != -1)
		return ret;
	ret = LNF;
	ll t;
	if (s > 1) {
		if (!flag)
			t = v[s].first - v[s - 1].first;
		else
			t = v[e].first - v[s - 1].first;
		ret = min(ret, dp(s - 1, e, 0) + t * (w[s-1] + w[N] - w[e]));
	}
	if (e < N) {
		if (flag)
			t = v[e + 1].first - v[e].first;
		else
			t = v[e + 1].first - v[s].first;
		ret = min(ret, dp(s, e + 1, 1) + t * (w[s-1] + w[N] - w[e]));
	}
	return ret;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	v.resize(N+1);
	for (int i = 1; i <= N; i++) {
		cin >> v[i].first >> v[i].second;
		w[i] = w[i - 1] + v[i].second;
	}
	memset(d, -1, sizeof(d));
	cout << min(dp(M, M, 0), dp(M, M, 1)) << "\n";
}