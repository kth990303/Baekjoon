// 201130 #16968 ������ȣ��1 Bronze II
// 1. ��Ʈ��ŷ
// 2. ����
// ������ Ǯ��
#include <iostream>
#include <string>
using namespace std;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	string s;
	int ans = 1;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'c') {
			// ù ��° ���ڿ����� �ߺ��� ���� �ʿ䰡 ����
			if (!i || s[i - 1] != s[i])
				ans *= 26;
			// 26*25*24... �� �ƴ϶�, �ձ��ڿ͸� ������ �ǹǷ�
			// 26*25*25... �̷�������
			else
				ans *= 25;
		}
		else {
			if (!i || s[i - 1] != s[i])
				ans *= 10;
			else
				ans *= 9;
		}
	}
	cout << ans << "\n";
}