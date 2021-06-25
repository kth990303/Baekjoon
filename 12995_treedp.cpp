// 210625 #12995 트리나라 Platinum III
// treedp
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
ll N, K, d[MAX][MAX][MAX];
vector<int> v[MAX], c[MAX];
bool visit[MAX];
void init(int cur) {
	visit[cur] = true;
	for (auto i : v[cur]) {
		if (!visit[i]) {
			c[cur].push_back(i);
			init(i);
		}
	}
}
ll dp(int cur, int idx, int n) {
	if (!n) return 1;
	if (idx == c[cur].size())
		return n == 1 ? 1 : 0; // include root
	ll& ret = d[cur][idx][n];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = 0; i < n; i++) {
		// new component * next child component
		ret += dp(c[cur][idx], 0, i) * dp(cur, idx + 1, n - i);
		ret %= MOD;
	}
	return ret % MOD;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	init(1);
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		memset(d, -1, sizeof(d));
		ans += dp(i, 0, K);
		ans %= MOD;
	}
	cout << ans << "\n";
}