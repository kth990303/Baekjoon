// 210322 #11085 군사 이동 Gold II
// I think it's Gold IV ~ Gold III
// like mst, but not mst. (reverse mst) union-find
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 1001;
int N, M, S, E, p[MAX], ans;
vector <pair<int, pair<int, int>>> v;
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

	cin >> N >> M >> S >> E;
	for (int i = 0; i < N; i++) {
		p[i] = i;
	}
	for (int i = 0; i < M; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		v.push_back({ cost, {a,b} });
	}
	sort(v.begin(), v.end());
	for (int i = v.size() - 1; i >= 0; i--) {
		int node1 = v[i].second.first;
		int node2 = v[i].second.second;
		int cost = v[i].first;
		merge(node1, node2);
		if (find(S) == find(E)) {
			ans = cost;
			break;
		}
	}
	cout << ans << "\n";
}