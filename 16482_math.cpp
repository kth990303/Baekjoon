// 200912 #16482 �� ������ ������! Platinum III
// ü���� ������ ���� ������ ����
// �÷ο��ſ��� ��2cos��Ģ, ���Ϸ� ������ �ʹ� �����ϴ� �� ����
#include <iostream>
#include <cmath>
using namespace std;
double a, b, c, d, e;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cout << fixed;
	cout.precision(10);

	cin >> a >> b >> c >> d >> e;
	double ans = (c - d) * (a - e) * b / ((c - d) * (a - e) + d * e);
	cout << ans << "\n";
}