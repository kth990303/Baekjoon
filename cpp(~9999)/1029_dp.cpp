// 210526 #1029 그림교환 Gold I
// bitmask_dp
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
const int MAX = 16;
int N, a[MAX][MAX], d[MAX][1 << 15][10], ans;
int dp(int cur, int flag, int n) {
	if (cur == N)
		return 0;
	int& ret = d[cur][flag][n];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 0; i < N; i++) {
		if (a[cur][i] >= n && !(flag & (1 << i))) {
			ret = max(ret, dp(i, flag | (1 << i), a[cur][i]) + 1);
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
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			a[i][j] = (int)(s[j] - '0');
		}
	}
	memset(d, -1, sizeof(d));
	cout << dp(0, 1, 0) + 1 << "\n";
}