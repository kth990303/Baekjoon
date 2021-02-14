// 210214 #17609 회문 Silver I
// 더욱 간단한 풀이
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
bool check(string s, int left, int right) {
	while (left < right) {
		if (s[left++] != s[right--])
			return false;
	}
	return true;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		string s;
		int ans = 0;
		cin >> s;
		for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
			if (s[i] != s[j]) {
				if (check(s, i + 1, j) || check(s, i, j - 1))
					ans = 1;
				else
					ans = 2;
				break;
			}
		}
		cout << ans << "\n";
	}
}