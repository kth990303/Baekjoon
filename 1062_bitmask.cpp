// 210130 #1062 °¡¸£Ä§ Gold IV
// bitmasking + backtracking
// backtracking: 128ms, bitmasking: 28ms
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
int N, K, ans, used;	// used: alphabet->bitmask array (1<<26)
vector<int> v;
void solve(int k, int num) {
	if (!k) {
		int ret = 0;
		// used bitmask
		for (int i = 0; i < N; i++) {
			if ((used & v[i]) == v[i])
				ret++;
		}
		ans = max(ans, ret);
		return;
	}
	for (int i = num; i < 26; i++) {
		if (!(used & 1<<i)) {
			used|=1<<i;
			solve(k - 1, i);
			// ~(1<<i): 0
			used&=~(1<<i);
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		int k = 0;
		for (int i = 4; i < s.length() - 4; i++) {
			k |= 1 << (s[i] - 'a');
		}
		// string bitmask in vector
		v.push_back(k);
	}
	if (K < 5) {
		cout << 0 << "\n";
		return 0;
	}
	else if (K >= 26) {
		cout << N << "\n";
		return 0;
	}
	used |= 1 << ('a' - 'a');
	used |= 1 << ('n' - 'a');
	used |= 1 << ('t' - 'a');
	used |= 1 << ('i' - 'a');
	used |= 1 << ('c' - 'a');
	K -= 5;
	solve(K, 0);
	cout << ans << "\n";
}