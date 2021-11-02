// 200903 #11694 Nim Game Platinum III
// ��Ÿ�� ��մٱ淡 �غôµ� ��Ʊ⸸ �� �Ф�
// �� ���� 0�̸� ���� 0�� �ƴϸ� �̱�
// �� ���� ����Ų���ó�� �������� �������� ����� ���Ƿ�
// �� �� ��ٷο�.
#include <iostream>
using namespace std;
const int MAX = 101;
int N, p[MAX], ans;
int xorRet() {
	for (int i = 1; i <= N; i++) {
		ans ^= p[i];
	}
	return ans;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	int cnt = 0;	// ���� 1���� ������ ����
	for (int i = 1; i <= N; i++) {
		cin >> p[i];
		// ���� 1���� ������ ������ ���� ��.
		if (p[i] == 1)
			cnt++;
	}
	// ���� 1���� ���̸����� ������ �� ����ó�� ���ֱ�
	if (cnt == N) {
		if (!(cnt % 2))
			cout << "koosaga" << "\n";
		else
			cout << "cubelover" << "\n";
		return 0;
	}
	// ���� 1���� ���̰� ¦������ ��, Ȧ������ ������ֱ�
	if (!(cnt % 2) && cnt != 0) {
		for (int i = 1; i <= N; i++) {
			if (p[i] != 1) {
				p[i] = 1;
				break;
			}
		}
	}
	// ���� �� 0�̸� �İ�, 0�� �ƴϸ� �����ؼ� 0���� ����������~
	if (!xorRet())
		cout << "cubelover" << "\n";
	else
		cout << "koosaga" << "\n";
}