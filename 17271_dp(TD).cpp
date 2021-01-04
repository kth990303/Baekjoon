// 210104 #17271 리그오브레전설(Small) Silver I
// DP (top-down) O(N)
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 10001;
const int MOD = 1000000007;
int N, M, d[MAX];
int dp(int time) {
	int& ret = d[time];
	if (ret != -1)
		return ret;
	// if exceed N, not correct combi.
	if (time > N)
		return ret = 0;
	// if equal N, correct combi.
	else if (time == N)
		return ret = 1;
	ret = dp(time + 1) % MOD;
	if (time + M <= N) {
		ret += dp(time + M);
		ret %= MOD;
	}
	return ret % MOD;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	fill(d, d + MAX, -1);
	cout << dp(0) << "\n";
}