// 210603 #17619 개구리 점프 Gold III
// union_find + line_sweeping
#include <iostream>
#include <algorithm>
#include <vector>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 100001;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int N, Q, p[MAX];
vector<pair<pi, pi>> v;
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
	if (a > b)
		swap(a, b);
	p[b] = a;
	return true;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> Q;
	v.resize(N);
	for (int i = 1; i <= N; i++) {
		p[i] = i;
	}
	for (int i = 0; i < N; i++) {
		cin >> v[i].first.first >> v[i].first.second >> v[i].second.first;
		v[i].second.second = i + 1;
	}
	sort(all(v));
	int s = 0, e = 0, left = v[0].first.first, right = v[0].first.second;
	while (s < N) {
		if (e < N - 1 && v[e + 1].first.first <= right) {
			merge(v[e].second.second, v[e + 1].second.second);
			left = min(left, v[e + 1].first.first);
			right = max(right, v[e + 1].first.second);
			e++;
		}
		else {
			s = e + 1;
			e = s;
			if (s >= N)
				break;
			left = v[s].first.first;
			right = v[s].first.second;
		}
	}
	while (Q--) {
		int a, b;
		cin >> a >> b;
		if (find(a) == find(b))
			cout << 1 << "\n";
		else
			cout << 0 << "\n";
	}
}