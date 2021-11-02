// 210114 #2602 돌다리 건너기 Gold IV
// dp(top-down) O(N^2)
#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 101;
string s, s1, s2;
int d[MAX][21][2];
int dp(int cur, int flag, string now) {
	int num = now.length();
	// length, count + flag memoization!
	int& ret = d[cur][num][flag];
	if (ret != -1)
		return ret;
	if (now == s)
		return ret = 1;
	if (now.length() >= s.length() || cur >= s1.length())
		return ret = 0;
	ret = 0;
	for (int i = cur; i < s1.length(); i++) {
		// devil
		if (!flag) {
			if (s1[i] == s[num]) {
				ret += dp(i + 1, flag + 1, now + s[num]);
			}
		}
		// angel
		else {
			if (s2[i] == s[num]) {
				ret += dp(i + 1, flag - 1, now + s[num]);
			}
		}
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> s >> s1 >> s2;
	memset(d, -1, sizeof(d));
	// devil + angel
	cout << dp(0, 0, "") + dp(0, 1, "") << "\n";
}