// 210403 #1102 ¹ßÀü¼Ò Gold I
// bitmask + dp (because we need to check status)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
const int MAX = 17;
const int INF = 1e9 + 7;
int N, a[MAX][MAX], visit, d[1<<MAX][MAX], cnt;
int dp(int cur, int n) {
	int& ret = d[cur][n];
	if (ret != -1)
		return ret;
	if (n >= cnt)
		return ret = 0;
	ret = INF;
	for (int i = 0; i < N; i++) {
		if (cur & (1 << i)) {
			for (int j = 0; j < N; j++) {
				if (!(cur & (1 << j))) {
					// cur|=(1<<j) is wrong
					ret = min(ret, dp(cur | (1 << j), n + 1) + a[i][j]);
				}
			}
		}
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
	string s;
	cin >> s >> cnt;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'Y') {
			visit |= 1 << i;
			cnt--;
		}
	}
	memset(d, -1, sizeof(d));
	int ans = dp(visit, 0);
	if (ans >= INF)
		cout << -1 << "\n";
	else
		cout << ans << "\n";
}