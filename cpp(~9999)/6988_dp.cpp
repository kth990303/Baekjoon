// 211129 #6988 ≈∏¿œπ‚±‚ Gold I
// dp O(N^2lgN)
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
const int MAX = 3011;
const int INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
ll N, d[MAX][MAX];
vector<int> v;
ll dp(int n1, int n2) {
	ll& ret = d[n1][n2];
	if (ret != -1)
		return ret;
	ret = 0;
	int idx = lower_bound(all(v), v[n2] * 2 - v[n1]) - v.begin();
	if (idx > n2 && idx < N && v[idx] == v[n2] * 2 - v[n1])
		ret = max(1LL * v[n2] + v[idx], dp(n2, idx)) + 1LL*v[n1];
	return ret;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	memset(d, -1, sizeof(d));
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			ans = max(ans, dp(i, j));
		}
	}
	cout << ans << "\n";
}