// 200903 #11868 NimGame II Platinum IV
// ����Ų��󽺿� �ݴ�. ���߿� ������ ����� ����.
// �̹��� Ǯ������ �������ϰ� �;�����...
// �̷� ���� ����ó�� ���� ���� �ո� �������
#include <iostream>
using namespace std;
const int MAX = 101;
int N, p[MAX], ans;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> p[i];
		ans ^= p[i];
	}
	// ���� ���� 0�� ��� ���Ƿ�
	if (!ans)
		cout << "cubelover" << "\n";
	// ���� ���� ���ϸ��� 0���� �ĵ� ���������⸸ �ϸ�ǹǷ�
	else
		cout << "koosaga" << "\n";
}