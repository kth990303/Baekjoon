// 200917 #3111 �˿� Platinum V
// ���� stack ����� �ϳ��� �� �ʿ���
// �ٸ�, stack�� pop�� �����ؾ� ��
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a, t, rev;
string s1, s2;
bool check(bool stat) {
	if (stat) {
		if (s1.length() < a.length())
			return false;
		for (int i = 0; i < a.length(); i++) {
			if (s1[s1.length() - i - 1] != rev[i])
				return false;
		}
		s1.erase(s1.end()-a.length(), s1.end());
	}
	else {
		if (s2.length() < a.length())
			return false;
		for (int i = 0; i < a.length(); i++) {
			if (s2[s2.length() - i - 1] != a[i])
				return false;
		}
		s2.erase(s2.end() - a.length(), s2.end());
	}
	return true;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> a >> t;
	// a�� �Ųٷ� ���� �������ƾ� ��
	for (int i = a.length() - 1; i >= 0; i--) {
		rev += a[i];
	}
	int s = 0, e = t.length() - 1;
	bool stat = true;
	while (s <= e) {
		// �տ������� �ľ�
		if (stat) {
			s1 += t[s];
			s++;
		}
		// �ڿ������� �ľ�
		else {
			s2 += t[e];
			e--;
		}
		// s1�̳� s2�� a�� �ִ��� �ľ��ϰ�
		// ������ �׸�ŭ ���� (erase)
		// �׸��� stat�� !stat����
		if(check(stat))
			stat = !stat;
	}
	string ans;
	// �������鼭 �� a�� ���� �� ����
	// ���� �� �� �� ����
	for (int i = s2.length()-1; i>=0; i--) {
		s1 += s2[i];
		check(true);
	}
	cout << s1 << "\n";
}