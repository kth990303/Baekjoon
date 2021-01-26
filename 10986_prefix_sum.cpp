// 210126 #10986 ������ �� Gold IV
// prefix_sum + Math
#include <iostream>
using namespace std;
typedef long long ll;
const int MAX = 1000001;
// collection of numbers with the rest equal
ll N, M, a[MAX], s[MAX], c[1001], ans;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
		s[i] %= M;
		// �κ��� ���������� ��� ����
		c[s[i]]++;
	}
	// �������� 0�̸� �� ������ ���� ����
	// if !rest -> ans += itself
	ans += c[0];
	for (int i = 0; i < M; i++) {
		// ���׵鳢�� �����ذ� ������ϰ�
		// Combination
		ans += c[i] * (c[i] - 1) / 2;
	}
	cout << ans << "\n";
}