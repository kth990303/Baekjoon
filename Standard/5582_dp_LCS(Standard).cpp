#include <iostream>
// 210106 #5582 공통 부분 문자열 Gold V
// DP (lcs) : Bottom-Up is easier than top-down.
// O(N^2)
#include <string>
#include <algorithm>
using namespace std;
const int MAX = 4001;
string s1, s2;
int d[MAX][MAX], ans;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> s1 >> s2;
	for (int i = 0; i < s1.length(); i++) {
		for (int j = 0; j < s2.length(); j++) {
			if (s1[i] == s2[j]) {
				// d[-1][-1] index
				if (!i || !j)
					d[i][j] = 1;
				else
					d[i][j] = d[i - 1][j - 1] + 1;
				ans = max(ans, d[i][j]);
			}
		}
	}
	cout << ans << "\n";
}