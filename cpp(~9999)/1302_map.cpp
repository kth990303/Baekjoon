// 210210 #1302 º£½ºÆ®¼¿·¯ Silver IV
// (data structure)map, string
#include <iostream>
#include <map>
#include <string>
#include <algorithm>
using namespace std;
map<string, int> m;
int N, cnt;
string s, ans;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		m[s]++;
		if (cnt <= m[s]) {
			cnt == m[s] ? ans = min(ans, s) : ans = s;
			cnt = m[s];
		}
	}
	cout << ans << "\n";
}