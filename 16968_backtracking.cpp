// #16968 ������ȣ��1 Bronze II
// 1. ��Ʈ��ŷ Ǯ��
// ��� ��Ʈ��ŷ�̶� �ϱ⵵ ���ϴ�.
#include <iostream>
#include <string>
using namespace std;
int ans[4], idx;
void check(char c1, char c2) {
	if (c1 == 'c') {
		ans[idx] = 26;
		// �ߺ��� ���
		if (c2 == 'c')
			ans[idx]--;
	}
	else {
		ans[idx] = 10;
		if (c2 == 'd')
			ans[idx]--;
	}
	idx++;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;
	int cnt = 1;
	for (int i = 0; i < s.length(); i++) {
		// ��Ʈ��ŷ�� ����
		// ù��° ���ڿ� �ι�° ���ڿ� ����
		check(s[i], s[i + 1]);
		// ����� �ٲ��.
		// ���� ���⼭�� �� �� ����� �������� �����Ƿ�
		// ������ �����ڸ� ��Ʈ��ŷ�̶� �ϱ⵵ �� �׷��� �ϴ�.
		cnt *= ans[i];
	}
	cout << cnt;
}