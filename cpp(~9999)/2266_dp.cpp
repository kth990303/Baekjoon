// 210425 #2266 금고테스트 Gold II
// I think it's Gold I
// binary Search? No, lots of safes
// d[n-1][k-1] vs d[n-h][k] => dp
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
typedef long long ll;
using namespace std;
const int MAX = 501;
const int INF = 1e9 + 7;
int N, K, ans, d[MAX][MAX];
int dp(int cur, int cnt) {
	int& ret = d[cur][cnt];
	if (ret != -1)
		return ret;
	if (cnt == 1 || cur <= 1)
		return ret = cur;
	ret = INF;
	for (int i = 1; i <= cur; i++) {
		ret = min(ret, max(dp(i - 1, cnt - 1), dp(cur - i, cnt)) + 1);
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	memset(d, -1, sizeof(d));
	cout << dp(N, K) << "\n";
}