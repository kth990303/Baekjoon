// 210714 #2836 수상택시 Gold III
// greedy + sort + sweeping
// O(N)
#include <iostream>
#include <algorithm>
#include <vector>
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const int MAX = 300001;
ll N, M, ans;
vector<pi> v;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	ans = M;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		if (a > b)
			v.push_back({ b, a });
	}
	sort(all(v));
	ll s = v[0].first, e = v[0].second;
	for (int i = 1; i < v.size(); i++) {
		if (e < v[i].first) {
			ans += 2 * (e - s);
			s = v[i].first;
		}
		// do not e=v[i].second;
		e = max(e, v[i].second);
	}
	cout << ans + 2 * (e - s) << "\n";
}