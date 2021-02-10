// 210210 #2624 동전 바꿔주기 Gold V
// dynamic programming
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 101;
const int MAX_T = 10001;
int T, K, p[MAX], n[MAX], d[MAX_T][MAX];
int dp(int money, int cur) {
	int& ret = d[money][cur];
	if (ret != -1)
		return ret;
	if (!money)
		return ret = 1;
	if (cur >= K)
		return ret = 0;
	ret = 0;
	// $n case 0, 1, 2, ... n[cur]
	// and each case recursion
	for (int i = 0; i <= n[cur]; i++) {
		if (money - i * p[cur] >= 0) {
			ret += dp(money - i * p[cur], cur + 1);
		}
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> T >> K;
	for (int i = 0; i < K; i++) {
		cin >> p[i] >> n[i];
	}
	memset(d, -1, sizeof(d));
	cout << dp(T, 0) << "\n";
}