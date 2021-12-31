// 220101 #24041 Good Bye BOJ 2021! C번
// parametric_search, binary_search
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
const int MAX = 200011;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e16;
const int MOD = 1e9 + 7;
ll N, G, K;
vector<pl> v1, v2;
ll check(ll s, ll e) {
	ll ans = 0;
	while (s <= e) {
		ll mid = (s + e) / 2;
		ll ret = 0;
		for (int i = 0; i < (ll)v1.size(); i++) {
			ret += v1[i].first * max(1LL, mid - v1[i].second);
		}
		vector<ll> tmp;
		for (int i = 0; i < (ll)v2.size(); i++) {
			tmp.push_back(v2[i].first * max(1LL, mid - v2[i].second));
		}
		sort(all(tmp));
		for (int i = 0; i < max(0LL, (ll)v2.size() - K); i++) {
			ret += tmp[i];
		}
		if (ret <= G) {
			ans = mid;
			s = mid + 1;
		}
		else
			e = mid - 1;
	}
	return ans;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> G >> K;
	for (int i = 0; i < N; i++) {
		ll s, l, o;
		cin >> s >> l >> o;
		if (o) {
			v2.push_back({ s, l });
		}
		else v1.push_back({ s, l });
	}
	cout << check(0, 1e10);
}