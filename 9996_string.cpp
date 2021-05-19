// 210519 #9996 한국이 그리울 땐 서버에 접속하지 Silver III
// string practice
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int MAX = 101;
int N, idx;
string s, a, b;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '*') {
			idx = i;
			a = string(s.begin(), s.begin() + i);
			b = string(s.begin() + i + 1, s.end());
			break;
		}
	}
	while (N--) {
		string p;
		cin >> p;
		bool flag1 = false, flag2 = false;
		int pidx = 0;
		if (a.length() + b.length() <= p.length() && p.substr(0, a.length()) == a) {
			flag1 = true;
			pidx = a.length();
		}
		if (flag1) {
			for (int i = pidx; i + b.length() <= p.length(); i++) {
				if (string(p.begin() + i, p.end()) == b)
					flag2 = true;
			}
		}
		if (flag2)
			cout << "DA\n";
		else
			cout << "NE\n";
	}
}