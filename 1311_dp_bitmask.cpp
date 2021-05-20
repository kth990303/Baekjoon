// 210520 #1311 할 일 정하기 1 Gold I
// dp + bitmask (Standard)
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 21;
const int INF = 0x3f3f3f3f;
int N, a[MAX][MAX], d[MAX][1 << 21];
int dp(int cur, int flag) {
	if (cur >= N)
		return flag == (1 << N) - 1 ? 0 : INF;
	int& ret = d[cur][flag];
	if (ret != -1)
		return ret;
	ret = INF;
	for (int i = 0; i < N; i++) {
		if (!(flag & (1 << i)))
			ret = min(ret, dp(cur + 1, flag | (1 << i)) + a[cur][i]);
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
		}
	}
	memset(d, -1, sizeof(d));
	cout << dp(0, 0) << "\n";
}