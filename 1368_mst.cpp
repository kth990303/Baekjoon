// 210131 #1368 ¹°´ë±â Gold III
// MST + greedy
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 301;
const int INF = 1e9 + 7;
typedef pair<int, pair<int, int>> pii;
vector<pii> v;
int N, a[MAX], p[MAX];
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

	cin >> N;
	for (int i = 0; i <= N; i++){
		p[i] = i;
	}
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		// itself -> regardless of the order
		v.push_back({ a[i], {0, i} });
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			int num;
			cin >> num;
			v.push_back({ num, {i, j} });
		}
	}
	sort(v.begin(), v.end());
	int ans = 0;
	for (int i = 0; i < v.size(); i++) {
		int node1 = v[i].second.first;
		int node2 = v[i].second.second;
		int cost = v[i].first;
		if (merge(node1, node2)) {
			ans += cost;
		}
	}
	cout << ans << "\n";
}