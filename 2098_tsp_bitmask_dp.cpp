// 200820 #2098 TSP algorithm_bit masking
// bitmask practice_Gold I
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int INF = 1000000000;
int n;
int a[16][16];
int dp[16][1 << 16]; // (O(N*2^N))
int dfs(int cur, int visit) {
	if (dp[cur][visit] != -1)
		return dp[cur][visit];
	// 1<<n -1: 11111...1(2): 전부 방문하였을 경우
	if (visit == (1 << n) - 1) {
		// 다 방문했을 경우 시작점으로 되돌아가기
		if (a[cur][0]) {
			return a[cur][0];
		}
		// 시작점으로 못돌아갈 경우
		return INF;
	}
	// 아직 다 방문 안했을 경우 탐색
	dp[cur][visit] = INF;
	for (int i = 0; i < n; i++) {
		// 방문이 가능하며 아직 방문 안한 경우
		if (!(visit & (1 << i)) && a[cur][i]) {
			// 방문하는 경우 1로 바꾸기
			// O(N^2 * 2^N)
			dp[cur][visit] = min(dp[cur][visit], dfs(i, visit | (1 << i)) + a[cur][i]);
		}
	}
	return dp[cur][visit];
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << dfs(0, 1);
}