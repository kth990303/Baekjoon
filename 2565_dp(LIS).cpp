// 210108 #2565 ภüฑ๊มู Silver I
// LIS O(N^2)
// N<=100, but idx<=500
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 501;
int N, a[MAX], d[MAX][MAX], ans = 2e9 + 7, maxNum;
bool visit[MAX];
int dp(int cur, int num) {
	int& ret = d[cur][num];
	if (ret != -1)
		return ret;
	if (cur > maxNum)
		return ret = 0;
	ret = 1;	// itself: 1
	for (int i = cur; i <= maxNum; i++) {
		if (num < a[i])
			ret = max(ret, dp(i, a[i]) + 1);
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int num, c;
		cin >> num >> c;
		a[num] = c;
		visit[num] = true;
		maxNum = max(maxNum, num);
	}
	memset(d, -1, sizeof(d));
	// ex01: dp(1, a[1]) < dp(2, a[2]) ...
	for (int i = 0; i < MAX; i++) {
		if (visit[i])
			ans = min(ans, N - dp(i, a[i]));
	}
	cout << ans << "\n";
}