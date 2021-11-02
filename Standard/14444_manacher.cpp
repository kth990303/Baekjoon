// 210305 #14444 가장 긴 팰린드롬 부분 문자열 Platinum V
// Manacher's Algorithm
// center -> radius check
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 100001;
string s, tmp;
int p[MAX * 2], ans;
void manacher(string s) {
	int r = 0, c = 0;
	for (int i = 0; i < s.length(); i++) {
		if (i <= r)
			p[i] = min(p[c * 2 - i], r - i);
		while (i - p[i] - 1 >= 0 && i + p[i] + 1 < s.length() && s[i - p[i] - 1] == s[i + p[i] + 1]) {
			p[i]++;
		}
		if (r < i + p[i]) {
			r = i + p[i];
			c = i;
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> tmp;
	for (int i = 0; i < tmp.length(); i++) {
		s += '#';
		s += tmp[i];
	}
	s += '#';
	manacher(s);
	for (int i = 0; i < s.length(); i++) {
		ans = max(ans, p[i]);
	}
	cout << ans << "\n";
}