// 210116 #2342 Dance Dance Revolution Gold III
// dp(Top-down) O(N)
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 100001;
const int INF = 1e9 + 7;
int a[MAX], d[5][5][MAX], idx;
int cost(int s, int e) {
	if (s == 0)
		return 2;
	else if (s == e)
		return 1;
	else if (abs(e - s) == 2)
		return 4;
	return 3;
}
int dp(int pos1, int pos2, int cur) {
	int& ret = d[pos1][pos2][cur];
	if (ret != -1)
		return ret;
	if (cur >= idx)
		return ret = 0;
	ret = INF;
	ret = min({ dp(pos1, a[cur], cur + 1) + cost(pos2, a[cur])
		, dp(a[cur], pos2, cur + 1) + cost(pos1, a[cur])
		, ret });
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	while (1) {
		int n;
		cin >> n;
		if (!n) break;
		a[idx++] = n;
	}
	memset(d, -1, sizeof(d));
	cout << dp(0, 0, 0) << "\n";
}