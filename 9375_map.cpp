// 210309 #9375 ÆÐ¼Ç¿Õ ½ÅÇØºó Silver III
// Math + Map
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		map<string, int> m;
		int N, ans = 1;
		cin >> N;
		for (int i = 0; i < N; i++) {
			string s1, s2;
			cin >> s1 >> s2;
			m[s2]++;
		}
		// Combination Case (middle school math)
		for (auto it = m.begin(); it != m.end(); it++) {
			ans *= (1 + it->second);
		}
		cout << ans - 1 << "\n";
	}
}