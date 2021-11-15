// 211115 #1146 지그재그서기 Platinum V
// dp
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
typedef pair<ll, pl> pll;
const int MAX = 103;
const int INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e6;
int N, d[MAX][MAX][2], ans;
int dp(int s, int e, int flag) {
	if (s + e == 0)return 1;
	int& ret = d[s][e][flag];
	if (ret != -1)return ret;
	ret = 0;
	if (flag == 0) {
		for (int i = 1; i <= e; i++) {
			ret += dp(s + i - 1, e - i, 1);
			ret %= MOD;
		}
	}
	else {
		for (int i = 1; i <= s; i++) {
			ret += dp(i - 1, s + e - i, 0);
			ret %= MOD;
		}
	}
	return ret;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	if (N == 1) {
		cout << 1 << "\n";
		return 0;
	}
	memset(d, -1, sizeof(d));
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i < j) {
				ans += dp(j - 2, N - j, 1);
				ans %= MOD;
			}
			if (i > j) {
				ans += dp(j - 1, N - j - 1, 0);
				ans %= MOD;
			}
		}
	}
	cout << ans << "\n";
}