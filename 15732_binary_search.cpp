// 210128 #15732 ���丮 ����� Gold II
// �ߺ��� �������� �ϴ� �̺�Ž��!
// binary_search
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int MAX = 1000001;
ll N, K, D;
vector <pair<pair<ll, ll>, ll>> v;
ll check(ll n) {
	ll sum = 0;
	for (int i = 0; i < K; i++) {
		if (min(n, v[i].first.second) >= v[i].first.first)
			sum += (min(n, v[i].first.second) -
				v[i].first.first) / v[i].second + 1;
	}
	return sum;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	//freopen("input.txt", "r", stdin);
	cin >> N >> K >> D;
	v.resize(K);
	ll s = N, e = N;
	for (int i = 0; i < K; i++) {
		cin >> v[i].first.first >> v[i].first.second
			>> v[i].second;
		s = min(s, v[i].first.first);
	}
	ll ans = 1e9 + 7;
	while (s <= e) {
		ll mid = (s + e) / 2;
		ll num = check(mid);
		// why >=?
		// because of duplicate
		if (num >= D) {
			ans = min(ans, mid);
		}
		if (num >= D)
			e = mid - 1;
		else
			s = mid + 1;
	}
	cout << ans << "\n";
}