// 210524 #21774 가희와 로그 파일 Gold II
// binary_search + string parsing
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <string>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MAX = 200001;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
int N, Q;
vector<string> v[7];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		string a, b;
		cin >> a >> b;
		int lv = (int)(b[9] - '0');
		v[lv].push_back(a + b.substr(0, 8));
	}
	for (auto& i : v)
		sort(all(i));
	while (Q--) {
		string a, b, c, date1, date2;
		cin >> a >> b >> c;
		date1 = a + b.substr(0, 8);
		date2 = b.substr(b.find('#') + 1) + c.substr(0, 8);
		int lv = (int)(c[9] - '0');
		int ans = 0;
		for (int i = lv; i <= 6; i++) {
			int idx1 = lower_bound(all(v[i]), date1) - v[i].begin();
			int idx2 = upper_bound(all(v[i]), date2) - v[i].begin();
			ans += idx2 - idx1;
		}
		cout << ans << "\n";
	}
}