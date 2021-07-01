// 210701 #16132 구간 나누기(Subset) Gold III
// dp
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAX = 51;
ll N, S, d[MAX][638][26], tmp;
ll dp(int cur, int n, int cnt) {
	if (cnt > N / 2)
		return 0;
	if (n == S / 2)
		return 1;
	ll& ret = d[cur][n][cnt];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = cur + 1; i <= N; i++) {
		ret += dp(i, n + i, cnt + 1);
	}
	return ret;
}
ll dp2(int cur, int n, int cnt) {
	if (cnt > N / 2)
		return 0;
	if (cnt == N / 2)
		return n == S / 2 ? 1 : 0;
	ll& ret = d[cur][n][cnt];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = cur + 1; i <= N; i++) {
		ret += dp2(i, n + i, cnt + 1);
	}
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
	memset(d, -1, sizeof(d));
	ll ans = dp(0, 0, 0);
	if (!(N % 2)) {
		memset(d, -1, sizeof(d));
		tmp = dp2(0, 0, 0) / 2;
	}
	cout << ans - tmp << "\n";
}