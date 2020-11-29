// 2670 ���Ӻκ��ִ�� Silver IV
// DP (�ݺ��� ���Ҿ� ��� �̿�)
// 84ms �ҿ�, 0msǮ�̰� ����.
#include <iostream>
#include <algorithm>
using namespace std;
double a[10001], d[10001];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cout << fixed;
	cout.precision(3);

	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	double ans = -1;
	for (int i = 0; i < N; i++) {
		d[i] = a[i];
		double tmp = a[i];
		for (int j = i + 1; j < N; j++) {
			tmp *= a[j];
			d[i] = max(d[i], tmp);
		}
		ans = max(ans, d[i]);
	}
	cout << ans << "\n";
}