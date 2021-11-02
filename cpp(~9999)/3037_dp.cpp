// 210519 #3037 È¥¶õ Gold I
// dp top-down
// if use prefix_sum -> O(NC)
// if not use prefix_sum -> O(N^2C)
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 1001;
const int MAXC = 10001;
const int MOD = 1e9 + 7;
int N, C, d[MAX][MAXC];
int dp(int cur, int c) {
	if (cur * (cur - 1) / 2 < c)
		return 0;
	if (!c)
		return 1;
	if (cur == 1)
		return !c ? 1 : 0;
	int& ret = d[cur][c];
	if (ret != -1)
		return ret;
	ret = 0;
	ret += dp(cur, c - 1) + dp(cur - 1, c);
	ret %= MOD;
	if (c >= cur)
		ret -= dp(cur - 1, c - cur);
	ret = (ret + MOD) % MOD;
	return ret % MOD;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> C;
	memset(d, -1, sizeof(d));
	cout << dp(N, C) << "\n";
}