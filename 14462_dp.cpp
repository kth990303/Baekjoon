// 210424 #14462 소가 길을 건너간 이유 8 Gold III
// dp
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 1001;
int N, a[MAX], b[MAX], d[MAX][MAX];
int dp(int cur1, int cur2) {
	int& ret = d[cur1][cur2];
	if (cur1 >= N || cur2 >= N)
		return ret = 0;
	if (ret != -1)
		return ret;
	ret = dp(cur1 + 1, cur2);
	for (int i = cur2; i < N; i++) {
		if (abs(a[cur1] - b[i]) <= 4) {
			ret = max(ret, dp(cur1 + 1, i + 1) + 1);
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
		cin >> a[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> b[i];
	}
	memset(d, -1, sizeof(d));
	cout << dp(0, 0) << "\n";
}