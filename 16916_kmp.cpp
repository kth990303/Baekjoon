// 200921 #16916 �κй��ڿ� Gold IV
// substr�θ� Ǯ�� 76ms ������ ���´�.
// KMP�� Ǯ�� O(N+M): 16ms ����
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s, p;
vector<int> fail() {
	int j = 0;
	vector<int> pi(p.length(), 0);
	for (int i = 1; i < p.length(); i++) {
		while (j > 0 && p[i] != p[j]) {
			j = pi[j - 1];
		}
		if (p[i] == p[j])
			pi[i] = ++j;
	}
	return pi;
}
int kmp() {
	vector<int> v;
	vector<int> pi = fail();
	int j = 0;
	for (int i = 0; i < s.length(); i++) {
		while (j > 0 && s[i] != p[j]) {
			j = pi[j - 1];
		}
		if (s[i] == p[j]) {
			if (j == p.length() - 1)
				return 1;
			else
				j++;
		}
	}
	return 0;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> s >> p;
	cout << kmp() << "\n";
}