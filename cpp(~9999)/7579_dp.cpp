// 210128 #7579 ¾Û Gold III
// dp : change idea reverse
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 101;
int N, M, m[MAX], c[MAX], d[MAX][10001];
// if memory in dp table, MLE TLE
// capacity in dp table

// return max memory
int dp(int cur, int capa) {
	int& ret = d[cur][capa];
	if (ret != -1)
		return ret;
	if (cur >= N)
		return ret = 0;
	ret = dp(cur + 1, capa);
	if (capa - c[cur] >= 0) {
		ret = max(ret, dp(cur + 1, capa - c[cur]) + m[cur]);
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	int sum = 0;
	for (int i = 0; i < N; i++) {
		cin >> m[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> c[i];
		sum += c[i];
	}
	memset(d, -1, sizeof(d));
	// when the return value meets the criteria
	// return 0
	for (int i = 0; i <= sum; i++) {
		if (dp(0, i) >= M) {
			cout << i << "\n";
			return 0;
		}
	}
}