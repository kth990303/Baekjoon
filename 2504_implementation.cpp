// 210118 #2504 °ýÈ£ÀÇ °ª Silver II
// Implementation. similar stack
// like calculator implementation.
#include <iostream>
#include <string>
using namespace std;
int cnt1, cnt2, cnt3, cnt4, ans;
string s;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> s;
	int tmp = 1, cnt = 0;
	for (int i = s.length()-1; i >= 0; i--) {
		char op = s[i];
		if (op == ')') {
			cnt3++;
			tmp *= 2;
		}
		else if (op == ']') {
			cnt4++;
			tmp *= 3;
		}
		else if (op == '(') {
			cnt1++;
			if (cnt1 > cnt3) {
				cout << 0 << "\n";
				return 0;
			}
			if (s[i + 1] == ')')
				ans += tmp;
			tmp /= 2;
		}
		else if (op == '[') {
			cnt2++;
			if (cnt2 > cnt4) {
				cout << 0 << "\n";
				return 0;
			}
			if (s[i + 1] == ']')
				ans += tmp;
			tmp /= 3;
		}
	}
	if (cnt1 != cnt3 || cnt2 != cnt4) {
		cout << 0 << "\n";
	}
	else {
		cout << ans << "\n";
	}
}