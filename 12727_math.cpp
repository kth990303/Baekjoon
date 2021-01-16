// 210116 #12727 Numbers(Small) Gold II
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
typedef unsigned long long ll;
const int MOD = 1000;
const int MAX = 31;
int d[MAX] = { 1,6,28, };
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	for (int i = 3; i < MAX; i++) {
		d[i] = (6 * d[i - 1] - 4 * d[i - 2]) + 10000;
		d[i] %= MOD;
	}
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		int N;
		string ans;
		cin >> N;
		ans = to_string((d[N] - 1) % MOD);
		for (int j = 0; j < 3 - ans.length(); j++) {
			cout << "0";
		}
		cout << ans << "\n";
	}
}