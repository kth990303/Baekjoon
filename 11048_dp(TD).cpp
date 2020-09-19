// 200919 #11048 이동하기 Silver I
// 탑다운 방식
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 1001;
int a[MAX][MAX], d[MAX][MAX], N, M;
int dp(int x, int y) {
	int& ret = d[y][x];
	if (ret != -1)
		return ret;
	ret = 0;
	if (x < M - 1)
		ret = max(ret, dp(x + 1, y));
	if (y < N - 1) {
		ret = max(ret, dp(x, y + 1));
	}
	if (x < M - 1 && y < N - 1) {
		ret = max(ret, dp(x + 1, y + 1));
	}
	ret += a[y][x];
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a[i][j];
		}
	}
	memset(d, -1, sizeof(d));
	cout << dp(0, 0) << "\n";
}