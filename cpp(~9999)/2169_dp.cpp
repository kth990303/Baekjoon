// 200821 #2169 dp Gold I
// �������� �� �� ��ưԽø�...
#include <iostream>
#include <algorithm>
using namespace std;
int a[1002][1002];
int dp[1002][1002];
int cmp[2][1002];
int N, M;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> a[i][j];
		}
	}
	// ������ �ʱ�ȭ. ������ 1,1�̴ϱ� ���������θ� �� ���ָ��
	for (int j = 1; j <= M; j++)
		dp[1][j] = dp[1][j-1]+a[1][j];
	
	for (int i = 2; i <= N; i++) {
		// �Ʒ� or ������
		for (int j = 1; j <= M; j++) {
			if (j == 1)
				cmp[0][j] = dp[i - 1][j] + a[i][j];
			else
				cmp[0][j] = max(dp[i - 1][j], cmp[0][j - 1]) + a[i][j];
		}
		// �Ʒ� or ����
		for (int j = M; j >=1; j--) {
			if (j == M)
				cmp[1][j] = dp[i - 1][j] + a[i][j];
			else
				cmp[1][j] = max(dp[i - 1][j], cmp[1][j + 1]) + a[i][j];
		}
		// �� ����~
		for (int j = 1; j <= M; j++) {
			dp[i][j] = max(cmp[0][j], cmp[1][j]);
		}
	}

	
	cout << dp[N][M];
}