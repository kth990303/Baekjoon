// 211215 #9463 순열그래프 Platinum V
// inversion counting fenwick version
// == icpc.me/7578
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
const int MAX = 100011;
const int INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int t, N, a[MAX], b[MAX], tree[MAX];
ll query(int i) {
	ll ret = 0;
	for (; i; i -= i & -i) {
		ret += 1LL * tree[i];
	}
	return ret;
}
void update(int i, int val) {
	for (; i <= N; i += i & -i) {
		tree[i] += val;
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> N;
		ll ans = 0;
		fill(tree + 1, tree + N + 1, 0);
		for (int i = 1; i <= N; i++) {
			int k;
			cin >> k;
			a[k] = i;
		}
		for (int i = 1; i <= N; i++) {
			int k;
			cin >> k;
			b[i] = a[k];
		}
		for (int i = 1; i <= N; i++) {
			ans += query(N) - query(b[i] - 1);
			update(b[i], 1);
		}
		cout << ans << "\n";
	}
}