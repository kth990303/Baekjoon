// 200921 #1305 ���� Platinum V
// KMP�� fail function ���� ����
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s;
int n;
// �������� kmp�� �����Լ�
vector<int> fail() {
	int j = 0;
	vector<int> pi(s.length(), 0);
	for (int i = 1; i < s.length(); i++) {
		while (j > 0 && s[i] != s[j]) {
			j = pi[j - 1];
		}
		// ���� ���� ���ڰ� ������ (���λ�=���̻�)
		if (s[i] == s[j])
			pi[i] = ++j;
	}
	return pi;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> s;
	vector<int> pi = fail();
	// ���λ簡 ���� �κ��� ������
	// ���� �κ��� ��������� ����� �׸�ŭ ª���� �� ����
	// �����ǿ��� ���λ� �κ��� �߰��� �������� ����
	cout << n - pi[n - 1] << "\n";
}