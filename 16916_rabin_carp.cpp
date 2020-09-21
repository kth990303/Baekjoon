// 라빈-카프 알고리즘
// 최선: O(N+M), 최악: O(NM)
// 좋은 해시함수를 만드는 것이 핵심 (주: 라빈 핑거프린트)
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
const int MOD = 127;
const int base = 256;
string s, p;
// 해시함수: Rabin-FingerPrint
// abcd: (97*256^3 + 98*256^2 + 99*256 + 100) % MOD
// 다음 위치의 해시값을 바로 구할 수 있기 때문에 자주 이용
int h(string s) {
	int ans = 0;
	for (char ch : s) {
		ans = (ans * base + ch) % MOD;
	}
	return ans;
}
int match(string s, string p) {
	int n = s.length();
	int m = p.length();
	if (n < m)
		return 0;
	int hash_p = h(p);
	int hash_s = h(s.substr(0, m));
	// first= pow(base, m-1)%MOD
	// 다음 문자열 비교 시, hash_s값을 변경해줘야 하므로
	int first = 1;
	for (int i = 0; i < m - 1; i++) {
		first = (first * base) % MOD;
	}
	for (int i = 0; i <= n - m; i++) {
		if (hash_p == hash_s) {
			if (s.substr(i, m) == p)
				return 1;
		}
		if (i + m < n) {
			hash_s = hash_s - (s[i] * first) % MOD;
			// hash_s가 음수가 될 수 있으므로
			hash_s = (hash_s + MOD) % MOD;
			hash_s = ((hash_s * base) % MOD + s[i + m]) % MOD;
		}
	}
	return 0;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> s >> p;
	cout << match(s, p) << "\n";
}