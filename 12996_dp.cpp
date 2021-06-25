// 210626 #12996 Acka Gold III
// dp, Á¶ÇÕ·Ð
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 51;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
int N, A,B,C, d[MAX][MAX][MAX][MAX], ans;
int dp(int cur, int a, int b, int c) {
	if (cur >= N)
		return (a == A && b == B && c == C) ? 1 : 0;
	int& ret = d[cur][a][b][c];
	if (ret != -1)
		return ret;
	ret = 0;
	if (a < A)
		ret += dp(cur + 1, a + 1, b, c);
	ret %= MOD;
	if (b < B)
		ret += dp(cur + 1, a, b + 1, c);
	ret %= MOD;
	if (c < C)
		ret += dp(cur + 1, a, b, c + 1);
	ret %= MOD;
	if (a < A && b < B)
		ret += dp(cur + 1, a + 1, b + 1, c);
	ret %= MOD;
	if (b < B && c < C)
		ret += dp(cur + 1, a, b + 1, c + 1);
	ret %= MOD;
	if (a < A && c < C)
		ret += dp(cur + 1, a + 1, b, c + 1);
	ret %= MOD;
	if (a < A && b < B && c < C)
		ret += dp(cur + 1, a + 1, b + 1, c + 1);
	ret %= MOD;
	return ret % MOD;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> A >> B >> C;
	memset(d, -1, sizeof(d));
	cout << dp(0, 0, 0, 0) << "\n";
}