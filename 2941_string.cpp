// 200923 #2941 ũ�ξ�Ƽ�� ���ĺ� Silver V
// C++�� �� python�� replace ����� ������
// ���� ������Ʈ�� �����
#include <iostream>
#include <string>
using namespace std;
string words[8] = { "c=", "c-", "dz=", "d-", "lj", "nj", "s=", "z=" };
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	string s, tmp;
	cin >> s;
	int cnt = 0;
	int ans = s.length();
	for (int i = 0; i < s.length(); i++) {
		tmp += s[i];
		// �־��� words �迭�� 8����
		for (int j = 0; j < 8; j++) {
			bool flag = true;
			for (int k = 0; k < words[j].length(); k++) {
				// ���̰� words[j]���� ª����
				// ��Ÿ�ӿ��� ������ ���� break
				if (tmp.length() < words[j].length()) {
					flag = false;
					break;
				}
				// �ڿ������� ���������� ��
				// tmp�� �� ���ϸ� ũ�ξ�Ƽ�� ���ĺ��ε� ������ ��� ����
				if (tmp[tmp.length() - 1 - k] != words[j][words[j].length() - k - 1]) {
					flag = false;
					break;
				}
			}
			// ���� ��� ũ�ξ�Ƽ�� ���ĺ� ���̸�ŭ ���ְ�
			if (flag) {
				cnt++;
				ans -= words[j].length();
				tmp = "";
				break;
			}
		}
	}
	// ũ�ξ�Ƽ�� ���ĺ���ŭ ����
	cout << ans + cnt << "\n";
}