// 200918 #2704 이진법 변환 Bronze II
// 이진법 변환 함수 solve함수 참고
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
using namespace std;
string s;
int N, ans[3][6];
void solve(int num, int stat) {
	for (int i = 0; num > 0; i++) {
		ans[stat][5-i] = num % 2;
		num /= 2;
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	while (N--) {
		memset(ans, 0, sizeof(ans));
		cin >> s;
		string a, b, c;
		int d, e, f;
		for (int i = 0; i < s.length(); i++) {
			if (i == 0 || i == 1)
				a += s[i];
			else if (i == 3 || i == 4)
				b += s[i];
			else if (i == 6 || i == 7)
				c += s[i];
		}
		d = stoi(a);
		solve(d, 0);
		e = stoi(b);
		solve(e, 1);
		f = stoi(c);
		solve(f, 2);

		for (int i = 0; i < 6; i++) {
			for (int j = 0; j < 3; j++) {
				cout << ans[j][i];
			}
		}
		cout << " ";
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 6; j++) {
				cout << ans[i][j];
			}
		}
		cout << "\n";
	}
}