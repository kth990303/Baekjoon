// 210901 #22985 문자열조작의달인 Gold I
// dp
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
const int MAX = 301;
const ll MOD = 1e9 + 7;
ll N, M, d[MAX][MAX * 25][2];
int a[MAX];
string s;
ll dp(int cur, int cnt, int flag) {
	if (cur >= N) {
		if (flag)
			return cnt <= M ? 1 : 0;
		else
			return cnt == M ? 1 : 0;
	}
	ll& ret = d[cur][cnt][flag];
	if (ret != -1)
		return ret;
	ret = 0;
	int n = 25 - a[cur];
	for (int i = 0; i <= n; i++) {
		a[cur] = n + i;
		if (i == n)
			ret += dp(cur + 1, cnt + i, 1);
		else
			ret += dp(cur + 1, cnt + i, flag);
		ret %= MOD;
		a[cur] = 25 - n;
	}
	return ret % MOD;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M >> s;
	ll num = 0;
	int flag = 0;
	for (int i = 0; i < N; i++) {
		a[i] = s[i] - 'a';
		num += (ll)25 - a[i];
		if (s[i] == 'z')
			flag = 1;
	}
	M = min(M, num);
	memset(d, -1, sizeof(d));
	cout << dp(0, 0, flag) % MOD << "\n";
}