// 211013 #23237 How Many Subtrees? Gold IV
// union_find + backtracking
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
const int MAX = 12;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e16;
const ll MOD = 1e9 + 7;
vector<pi> v, c;
int t, N, ans, d[MAX], p[MAX];
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
bool check() {
	for (int i = 0; i < N; i++) {
		p[i] = i;
		d[i] = 0;
	}
	for (int i = 0; i < c.size(); i++) {
		merge(c[i].first, c[i].second);
		d[c[i].first]++;
		d[c[i].second]++;
	}
	int k = 0, cnt = 0;
	for (int i = 0; i < N; i++) {
		if (!d[i])
			continue;
		if (!cnt) {
			cnt++;
			k = find(i);
			continue;
		}
		if (k != find(i))
			return false;
	}
	return true;
}
void solve(int cur, int cnt) {
	if (cur == N - 1) {
		if (check())
			ans++;
		return;
	}
	c.push_back(v[cur]);
	solve(cur + 1, cnt + 1);
	c.pop_back();
	solve(cur + 1, cnt);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	while (cin >> N && N) {
		ans = N;
		fill(d, d + MAX, 0);
		v.clear();
		c.clear();
		for (int i = 0; i < N - 1; i++) {
			int a, b;
			cin >> a >> b;
			if (a > b)
				swap(a, b);
			v.push_back({ a,b });
		}
		solve(0, 0);
		cout << "Case " << ++t << ": " << ans - 1 << "\n";
	}
}