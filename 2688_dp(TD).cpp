// 210323 #2688 줄어들지 않아 Gold V
// dp top-down, but bottom-up is easier
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAX = 65;
ll N, d[MAX][10];
ll dp(int cur, int n) {
	ll& ret = d[cur][n];
	if (ret != -1)
		return ret;
	if (cur == N - 1)
		return ret = 1;
	ret = 0;
	for (int i = 0; i <= n; i++) {
		ret += dp(cur + 1, i);
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		cin >> N;
		memset(d, -1, sizeof(d));
		ll ans = 0;
		for (int i = 0; i < 10; i++) {
			ans += dp(0, i);
		}
		cout << ans << "\n";
	}
}