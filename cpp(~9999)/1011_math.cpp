// 200912 #1011 Fly me to the Alpha Centauri Silver I
// ����� ���� ����
// �������� �������� 123454321 -> 25 -> 5^2 -> 7�� �̵�
// �������� ����, ���� ���� ������ �� �ǹ���?
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		int a, b;
		cin >> a >> b;
		int cnt = 0;
		double num = b - a, v = 0;
		for (int i = 1;; i++) {
			if (num >= pow(i, 2) && num < pow(i + 1, 2)) {
				cnt = 2 * i - 1;
				v = i;
				num -= pow(i, 2);
				break;
			}
		}
		cnt += ceil(num / v);
		cout << cnt << "\n";
	}
}