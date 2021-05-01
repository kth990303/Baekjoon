// 210501 #20951 유아와 곰두리차 Gold V
// not DAG, but only cnt<=7 -> dp[MAX][7+1]
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAX = 100001;
const int INF = 1e9 + 7;
ll N, M, d[MAX][8];
vector<int> v[MAX];
ll dp(int cur, int cnt) {
	ll& ret = d[cur][cnt];
	if (ret != -1)
		return ret;
	if (cnt == 7)
		return ret = 1;
	ret = 0;
	for (auto i : v[cur]) {
		ret += dp(i, cnt + 1);
		ret %= INF;
	}
	return ret % INF;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	while (M--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	memset(d, -1, sizeof(d));
	ll ans = 0;
	for (int i = 1; i <= N; i++) {
		ans += dp(i, 0);
		ans %= INF;
	}
	cout << ans << "\n";
}