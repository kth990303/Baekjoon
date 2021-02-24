// 210225 #1915 가장 큰 정사각형 Gold V
// dp top-down
// more difficult than bottom-up
// bruth-force? No, only check d[i-1][j], d[i][j-1], d[i-1][j-1]
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
const int MAX = 1001;
int N, M, a[MAX][MAX], d[MAX][MAX], ans;
int dp(int x, int y) {
	int& ret = d[y][x];
	if (ret != -1)
		return ret;
	if (!y || !x) {
		return ret = a[y][x];
	}
	ret = min({ dp(x - 1, y), dp(x, y - 1),
		dp(x - 1, y - 1) });
	ret += a[y][x] == 1 ? 1 : -ret;
	ans = max(ans, ret);
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			a[i][j] = s[j] - '0';
			if (a[i][j]) {
				ans = 1;
			}
		}
	}
	memset(d, -1, sizeof(d));
	dp(M - 1, N - 1);
	cout << ans * ans << "\n";
}