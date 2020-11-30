// 201130 #16968 차량번호판1 Bronze II
// 1. 백트래킹
// 2. 수학
// 수학적 풀이
#include <iostream>
#include <string>
using namespace std;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	string s;
	int ans = 1;
	cin >> s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'c') {
			// 첫 번째 글자에서는 중복을 따질 필요가 없음
			if (!i || s[i - 1] != s[i])
				ans *= 26;
			// 26*25*24... 가 아니라, 앞글자와만 따지면 되므로
			// 26*25*25... 이런식으로
			else
				ans *= 25;
		}
		else {
			if (!i || s[i - 1] != s[i])
				ans *= 10;
			else
				ans *= 9;
		}
	}
	cout << ans << "\n";
}