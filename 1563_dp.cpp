// 210213 #1563 °³±Ù»ó Gold IV
// dp
// three demension dp -> Gold IV
// but, not difficult
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
const int MAX = 1001;
const int MOD = 1e6;
int N, d[MAX][3][4];
// how many times he lates or absents?
// memoization
int dp(int cur, int late, int absent) {
	int& ret = d[cur][late][absent];
	if (ret != -1)
		return ret;
	if (cur > N)
		return ret = 0;
	if (cur == N && late < 2 && absent < 3)
		return ret = 1;
	ret = dp(cur + 1, late, 0);
	ret %= MOD;
	if (absent < 2){
		ret += dp(cur + 1, late, absent + 1);
		ret %= MOD;
	}
	if (late < 1) {
		ret += dp(cur + 1, late + 1, 0);
		ret %= MOD;
	}
	return ret % MOD;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	memset(d, -1, sizeof(d));
	cout << dp(0, 0, 0) << "\n";
}