// 211016 #22345 누적거리 Gold III
// math, prefix_sum, lower_bound
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
const int MAX = 200011;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e16;
const ll MOD = 1e9 + 7;
ll N, Q, p[MAX], cnt[MAX], d[MAX];
vector<ll> a;
vector<pl> v;
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		ll n, cost;
		cin >> n >> cost;
		a.push_back(cost);
		v.push_back({ cost, n });
	}
	sort(all(a));
	sort(all(v));
	for (int i = 1; i <= N; i++) {
		p[i] = p[i - 1] + v[i - 1].first;
		d[i] = d[i - 1] + v[i - 1].first * v[i - 1].second;
		cnt[i] = cnt[i - 1] + v[i - 1].second;
	}
	while (Q--) {
		ll n;
		cin >> n;
		ll idx = lower_bound(all(a), n) - a.begin();
		// absolute value expression organize
		cout << d[N] - 2 * d[idx] - (n * (cnt[N] - 2 * cnt[idx])) << "\n";
	}
}