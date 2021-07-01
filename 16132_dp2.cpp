// 210701 #16132 구간 나누기(Subset) Gold III
// dp 0ms
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAX = 51;
ll N, S, d[MAX][638], tmp;
ll dp(int cur, int n) {
	if (cur > N || n > S)
		return 0;
	if (n == S)
		return 1;
	ll& ret = d[cur][n];
	if (ret != -1)
		return ret;
	ret = 0;
	ret = dp(cur + 1, n) + dp(cur + 1, n + cur);
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	S = N * (N + 1) / 2;
	if (S % 2) {
		cout << 0 << "\n";
		return 0;
	}
	S /= 2;
	memset(d, -1, sizeof(d));
	cout << dp(1, 0) << "\n";
}