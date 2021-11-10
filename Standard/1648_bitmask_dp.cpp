// 211110 #1648 격자판채우기 Platinum III
// bitmask_dp (Standard)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
const int MAX = 14;
const double INF = 0x3f3f3f3f;
const ll LNF = 1e16;
const int MOD = 9901;
int N, M, d[MAX][MAX][1 << MAX];
int dp(int y, int x, int flag) {
	if (x == M)return dp(y + 1, 0, flag);
	if (y == N)return !flag ? 1 : 0;
	int& ret = d[y][x][flag];
	if (ret != -1)
		return ret;
	ret = 0;
	if (flag & 1)
		return ret = dp(y, x + 1, flag >> 1) % MOD;
	if (x < M - 1 && !(flag&2)) 
		ret += dp(y, x + 2, flag >> 2);
	ret %= MOD;
	if (y < N - 1)
		ret += dp(y, x + 1, (flag >> 1) | (1 << (M - 1)));
	ret %= MOD;
	return ret % MOD;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	if (N * M % 2) {
		cout << 0 << "\n";
		return 0;
	}
	memset(d, -1, sizeof(d));
	cout << dp(0, 0, 0) << "\n";
}