// 210921 #14574 ��콺Űģ Platinum V
// mst+dfs
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
const int MAX = 500001;
const int INF = 0x3f3f3f3f; 
int N, p[MAX];
vector<int> res[MAX];
vector<pi> c;
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
void trace(int cur, int prev) {
	for (auto i : res[cur]) {
		if (i == prev)
			continue;
		trace(i, cur);
	}
	if (prev != -1)
		cout << prev + 1 << " " << cur + 1 << "\n";
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	c.resize(N);
	for (int i = 0; i < N; i++) {
		p[i] = i;
		cin >> c[i].first >> c[i].second;
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int n = (c[i].second + c[j].second) / abs(c[i].first - c[j].first);
			v.push_back({ n, {i, j} });
		}
	}
	sort(all(v));
	reverse(all(v));
	ll ans = 0;
	for (int i = 0; i < v.size(); i++) {
		int n1 = v[i].second.first;
		int n2 = v[i].second.second;
		int score = v[i].first;
		if (find(n1) != find(n2)) {
			ans += score;
			merge(n1, n2);
			res[n1].push_back(n2);
			res[n2].push_back(n1);
		}
	}
	cout << ans << "\n";
	trace(0, -1);
}