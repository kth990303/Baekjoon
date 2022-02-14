// 220214 #10422 °ýÈ£ Gold IV
// catalan number solution : O(N)
// this solution (recursion dp): O(N^2)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
const int MAX = 5011;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e16;
const int MOD = 1e9 + 7;
ll N, d[MAX][MAX];
ll dp(ll left, ll right) {
	if (left < 0 || right < 0)return 0;
	if (left + right == 0)
		return !left && !right ? 1 : 0;
	ll& ret = d[left][right];
	if (~ret)return ret;
	ret = 0;
	ret += dp(left - 1, right);
	ret %= MOD;
	if (left < right) {
		ret += dp(left, right - 1);
		ret %= MOD;
	}
	return ret % MOD;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	memset(d, -1, sizeof(d));
	while (t--) {
		cin >> N;
		if (N % 2)cout << 0 << "\n";
		else {
			cout << dp(N/2, N/2) << "\n";
		}
	}
}