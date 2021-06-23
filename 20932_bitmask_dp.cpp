// 210623 #20932 약수 의식 Platinum V
// backtracking? we can memoization if same flag
// bitmask dp O(N^2*10*2^N)
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
const int MAX = 16;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
int N, a[MAX], mod;
ll d[10][1 << MAX], ans;
ll func(ll n) {
	if (!n)
		return 1;
	return func(n - 1) * n;
}
ll dp(int cur, int flag) {
	int cnt = 0;
	for (int i = 0; i < N; i++) {
		if (flag & (1 << i))
			cnt++;
	}
	if (cnt == N)
		return !cur ? 1 : 0;
	ll& ret = d[cur][flag];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 0; i < N; i++) {
		if (flag & (1 << i))
			continue;
		ret += dp((cur * 10 + a[i]) % mod, flag | (1 << i));
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cout << fixed;
	cout.precision(16);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < N; i++) {
		mod = a[i];
		memset(d, -1, sizeof(d));
		ans += dp(0, 1 << i);
	}
	cout << (double)ans / func(N) << "\n";
}