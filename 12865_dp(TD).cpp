// 200913 #12865 평범한 배낭 Gold V
// Knapsack 탑다운ver.
// 바탐업 말고 탑다운으로도 해보자
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 101;
const int W_MAX = 100001;
int N, K;
int w[MAX], v[MAX], d[MAX][W_MAX];
int dp(int cur, int k) {
	int& ret = d[cur][k];
	// 배열 idx 초과 시 return 0
	if (cur == N)
		return ret = 0;
	if (ret != -1)
		return ret;
	ret = dp(cur + 1, k);
	// 현재 물건을 더 넣을 수 있으면,
	if (k + w[cur] <= K) {
		// 더 넣어보고 maxRet과 비교
		ret = max(ret, dp(cur + 1, k + w[cur]) + v[cur]);
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> w[i] >> v[i];
	}
	memset(d, -1, sizeof(d));
	cout << dp(0,0) << "\n";
}