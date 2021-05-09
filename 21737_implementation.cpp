// 210509 #21737 SMUPC °è»ê±â Silver I
// implementation (calculator)
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int MAX = 500001;
int N, ans, tmpnum;
string s, tmp;
char ch = '+';
bool flag = false;
void solve() {
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= '0' && s[i] <= '9') {
			tmp += s[i];
		}
		else {
			if (ch == '+') {
				ans += stoi(tmp);
			}
			else if (ch == '-') {
				ans -= stoi(tmp);
			}
			else if (ch == '*') {
				ans *= stoi(tmp);
			}
			else if (ch == '/') {
				ans /= stoi(tmp);
			}
			tmp = "0";
			if (s[i] == 'P') {
				ch = '+';
			}
			else if (s[i] == 'M') {
				ch = '*';
			}
			else if (s[i] == 'S') {
				ch = '-';
			}
			else if (s[i] == 'U') {
				ch = '/';
			}
			else {
				flag = true;
				ch = '+';
				cout << ans << " ";
			}
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> s;
	solve();
	if (!flag)
		cout << "NO OUTPUT";
}