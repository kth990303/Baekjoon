// 210127 #1322 X�� K Gold IV
// bitmask
#include <iostream>
using namespace std;
typedef unsigned long long ll;
ll X, Y, K;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> X >> K;
	int cnt = 0;
	// K(2) �� �ڸ���
	while (K >> cnt) {
		cnt++;
	}
	int j = 0;
	for (int i = 0; i < cnt; i++) {
		// X�� �ڸ����� 0�� ������ ã��
		while (X & (1LL << j))
			j++;
		// K��° ū �� = K(2)�� 1�� �� �Ѳ����� ó��
		// �׷��� K��° ���� ����ϰ� ã��. ���� �������.
		if (K & (1LL << i))
			Y += (1LL << j);
		// �� ���� �ڸ�����
		j++;
	}
	cout << Y << "\n";
}