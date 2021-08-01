// 210801 #21924 도시건설 Gold IV
// MST Standard
#include <iostream>
#include <algorithm>
#include <vector>
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, pi> pii;
const int MAX = 100001;
const int INF = 0x3f3f3f3f;
int N, M, p[MAX];
ll sum, ans;
vector<pii> v;
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
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		p[i] = i;
	}
	while (M--) {
		int a, b;
		ll cost;
		cin >> a >> b >> cost;
		v.push_back({ cost, {a, b} });
		sum += cost;
	}
	sort(all(v));
	for (int i = 0; i < v.size(); i++) {
		int n1 = v[i].second.first;
		int n2 = v[i].second.second;
		if (find(n1) != find(n2)) {
			merge(n1, n2);
			ans += v[i].first;
		}		
	}
	for (int i = 2; i <= N; i++) {
		if (find(1) != find(i)) {
			cout << -1 << "\n";
			return 0;
		}
	}
	cout << sum - ans << "\n";
}