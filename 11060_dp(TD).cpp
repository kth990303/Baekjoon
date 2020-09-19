#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1001;
const int INF = 1000000007;
int N, a[MAX], d[MAX];
int dp(int cur) {
	// �� N-1�� ���� return 0�� �ϴ°�?
	// ������ ���̸� �̵����� �����Ƿ�.
	if (cur >= N - 1)
		return 0;
	int& ret = d[cur];
	if (ret != -1)
		return ret;
	ret = INF;
	for (int i = 1; i <= a[cur]; i++) {
		// �� 1�� ���ߴ°�?
		// �����ϸ鼭 1�� ������ ���̶� �񱳸� �ؾߵ�
		ret = min(ret, dp(cur + i) + 1);
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
	fill(d, d + N, -1);
	// �� ==�� �ƴϰ� >=�ΰ�?
	// �� �� ���� ĭ�� 1 ������ ���� ����
	if (dp(0) >= INF)
		cout << -1 << "\n";
	else
		cout << dp(0) << "\n";
}