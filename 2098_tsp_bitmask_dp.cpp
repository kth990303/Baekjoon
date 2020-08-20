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
	// 1<<n -1: 11111...1(2): ���� �湮�Ͽ��� ���
	if (visit == (1 << n) - 1) {
		// �� �湮���� ��� ���������� �ǵ��ư���
		if (a[cur][0]) {
			return a[cur][0];
		}
		// ���������� �����ư� ���
		return INF;
	}
	// ���� �� �湮 ������ ��� Ž��
	dp[cur][visit] = INF;
	for (int i = 0; i < n; i++) {
		// �湮�� �����ϸ� ���� �湮 ���� ���
		if (!(visit & (1 << i)) && a[cur][i]) {
			// �湮�ϴ� ��� 1�� �ٲٱ�
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