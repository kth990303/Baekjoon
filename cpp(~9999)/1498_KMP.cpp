// 200921 #1498 �ֱ⹮ Platinum V
// ���ڿ� ���� (4354)�� ���� ������ ����
// KMP�� �����Լ��� �̿�.
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s, p;
// �������� kmp�� �����Լ�
vector<int> fail() {
	int j = 0;
	vector<int> pi(s.length(), 0);
	for (int i = 1; i < s.length(); i++) {
		while (j > 0 && s[i] != s[j]) {
			j = pi[j - 1];
		}
		if (s[i] == s[j])
			pi[i] = ++j;
	}
	return pi;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> s;
	vector<int> v = fail();
	int n = s.length() - 1;
	for (int i = 1; i < s.length(); i++) {
		// �ֱ⸦ �̷���� �����Լ��� 0�̸� �ȵȴ�
		// 0�� ���� �ݺ��Ǵ� ���λ�, ���̻簡 �ƿ� ���� ���
		if (!v[i])
			continue;
		// ���� ���� % (�ݺ����� �ʴ� ����)�� 0�� ���
		// �ֱ⸦ �̷�� �ֱ⹮�� ����
		if (!((i+1) % ((i+1)-v[i]))) {
			cout << i + 1 << " " << (i+1) / (i+1 - v[i]) << "\n";
		}
	}
}