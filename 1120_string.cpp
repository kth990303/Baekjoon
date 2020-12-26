// 201226 #1120 ���ڿ� Silver IV
// ���ڿ� + �׸���(Silver V) + ����(+1)
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int INF = 1000000007;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	string a, b;
	cin >> a >> b;
	if (a.length() > b.length())
		swap(a, b);
	int ans = INF;
	// a�� ������ ª�� ���ڿ��� �ǹǷ�
	// �׸��� a, b�� ���ڿ� ���̴� �ִ� 50�� ���̹Ƿ�
	// a�� ��ĭ�� �̵���Ű�鼭 a�ǳ����� ��

	// �ٸ�, ���̴� ���� ���ƾ��ϹǷ� a�� ���� b�� ���� �������� ����������
	for (int i = 0; i <= b.length() - a.length(); i++) {
		int cnt = 0;	// �ٸ� ����
		for (int j = 0; j < a.length(); j++) {
			if (a[j] != b[i + j])
				cnt++;
		}
		// �� ���� ������ �� ����
		ans = min(ans, cnt);
	}
	cout << ans << "\n";
}