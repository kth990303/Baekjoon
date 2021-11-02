// 210319 #1543 문서 검색 Silver IV
// string substr
#include <iostream>
#include <string>
using namespace std;
string s, p;
int ans;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	getline(cin, s);
	getline(cin, p);
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == p[0]) {
			if (p == s.substr(i, p.length())) {
				ans++;
				i += p.length() - 1;
				continue;
			}
		}
	}
	cout << ans << "\n";
}