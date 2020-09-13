// 200913 #12865 ����� �賶 Gold V
// Knapsack ž�ٿ�ver.
// ��Ž�� ���� ž�ٿ����ε� �غ���
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 101;
const int W_MAX = 100001;
int N, K;
int w[MAX], v[MAX], d[MAX][W_MAX];
int dp(int cur, int k) {
	int& ret = d[cur][k];
	// �迭 idx �ʰ� �� return 0
	if (cur == N)
		return ret = 0;
	if (ret != -1)
		return ret;
	ret = dp(cur + 1, k);
	// ���� ������ �� ���� �� ������,
	if (k + w[cur] <= K) {
		// �� �־�� maxRet�� ��
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