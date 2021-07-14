// 210714 #22115 창영이와 커피 Gold V
// knapsack dp
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define all(v) (v).begin(), (v).end()
using namespace std;
const int MAX = 101;
const int INF = 0x3f3f3f3f;
int N, K, a[MAX], d[MAX][100001];
int dp(int cur, int n) {
	if (cur == N - 1)
		return n == K ? 1 : INF;
	int& ret = d[cur][n];
	if (ret != -1)
		return ret;
	ret = INF;
	ret = min(ret, dp(cur + 1, n));
	for (int i = cur + 1; i < N; i++) {
		if (n + a[i] <= K)
			ret = min(ret, dp(i, n + a[i]) + 1);
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	if (!K) {
		cout << 0 << "\n";
		return 0;
	}
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	memset(d, -1, sizeof(d));
	int ans = INF;
	for (int i = 0; i < N; i++) {
		ans = min(ans, dp(i, a[i]));
	}
	if (ans >= INF)
		cout << -1 << "\n";
	else
		cout << ans << "\n";
}