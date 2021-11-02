// 210114 #2225 ÇÕºÐÇØ Gold V
// dp (top-down) O(KN^2)
#include <iostream>
#include <cstring>
using namespace std;
const int MAX = 201;
const int MOD = 1e9;
int N, K, a[MAX], d[MAX][MAX];
int dp(int cur, int time) {
	int& ret = d[cur][time];
	if (ret != -1)
		return ret;
	if (time > K || cur < 0)
		return ret = 0;
	if (!cur && time == K)
		return ret = 1;
	ret = 0;
	for (int i = 0; i <= cur; i++) {
		ret += dp(cur - i, time + 1);
		ret %= MOD;
	}
	return ret % MOD;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	memset(d, -1, sizeof(d));
	cout << dp(N, 0) << "\n";
}