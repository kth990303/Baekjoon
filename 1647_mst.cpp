#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int p[100001];
int N, M, ans, num;
vector<pair<int, pair<int, int>>> v;
int find(int a) {
	if (a == p[a]) return a;
	else return p[a] = find(p[a]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b) return false;
	p[b] = a;
	return true;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++)
		p[i] = i;
	for (int i = 1; i <= M; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		v.push_back({ cost, {a,b} });
	}
	sort(v.begin(), v.end());
	// kruskal : 최대값 연결 안하면 두 컴포넌트에 정답!
	for (int i = 0; i < v.size(); i++) {
		if (num == N - 2) break;
		int w = v[i].first;
		int node1 = v[i].second.first;
		int node2 = v[i].second.second;
		if (merge(node1, node2)) {
			ans += w;
			num++;
		}
	}
	cout << ans;
}