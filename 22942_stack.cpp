// 210821 #22942 데이터체커 Gold V
// sweeping, stack, geometry
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 200001;
vector<pl> v, res;
int N, n;
bool cmp(pl p1, pl p2) {
	return p1.first - p1.second < p2.first - p2.second;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++)
		cin >> v[i].first >> v[i].second;
	sort(all(v), cmp);
	for (int i = 0; i < N; i++) {
		ll c = v[i].first;
		ll r = v[i].second;
		while (!res.empty() && res.back().first + res.back().second < c - r) {
			res.pop_back();
			n = res.back().first + res.back().second;
		}
		if (res.empty() ||
			abs(res.back().second - r) > c - res.back().first)
			res.push_back(v[i]);
		else {
			cout << "NO\n";
			return 0;
		}
	}
	cout << "YES\n";
}