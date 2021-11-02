#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int MAX = 1001;
const ll INF = 1e18;
int N, p[MAX];
vector<pair<int, pair<int, int>>> v;
int find(int a) {
	if (a == p[a])
		return a;
	return p[a] = find(p[a]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return false;
	p[b] = a;
	return true;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		p[i] = i;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int cost;
			cin >> cost;
			v.push_back({ cost, {i, j} });
		}
	}
	sort(v.begin(), v.end());
	ll ans = 0;
	for (int i = 0; i < v.size(); i++) {
		int node1 = v[i].second.first;
		int node2 = v[i].second.second;
		ll cost = (ll)v[i].first;
		if (merge(node1, node2)) {
			ans += cost;
		}
	}
	cout << ans << "\n";
}