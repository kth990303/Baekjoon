// 210509 #21734 SMUPC¿« µÓ¿Â Bronze II
// string, ascii(0~127)
#include <iostream>
#include <string>
using namespace std;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		int n = (int)s[i];
		int cnt = n / 100 + (n % 100) / 10 + n % 10;
		for (int j = 0; j < cnt; j++) {
			cout << s[i];
		}
		cout << "\n";
	}
}