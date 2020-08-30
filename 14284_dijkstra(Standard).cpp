// 200830 #14284 간선 이어가기 Gold V
// 아주 전형적인 dijkstra
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
const int MAX = 5001;
const int INF = 1000000007;
using namespace std;
typedef pair<int, int> pii;
int N, M, d[MAX];
vector<pii> v[MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		v[a].push_back({ cost, b });
		v[b].push_back({ cost, a });
	}
	int s, e;
	cin >> s >> e;

	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0,s });
	fill(d, d + MAX, INF);
	d[s] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (d[cur] < cost)
			continue;
		for (auto i : v[cur]) {
			int next = i.second;
			int nCost = i.first + cost;
			if (nCost < d[next]) {
				d[next] = nCost;
				pq.push({ nCost, next });
			}
		}
	}
	cout << d[e] << "\n";
}