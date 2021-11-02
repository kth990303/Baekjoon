// 210103 #2307 도로검문 Gold II
// dijkstra + trace
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
const int MAX = 1001;
const int INF = 1e9 + 7;
int N, M, d[MAX], trace[MAX];
vector<pair<int, int>> v[MAX];
int dijkstra(int s, int e) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0, 1 });
	fill(d, d + MAX, INF);
	d[1] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (d[cur] < cost)
			continue;
		for (auto i : v[cur]) {
			int nCost = i.first + cost;
			int next = i.second;
			if (cur == s && next == e)
				continue;
			else if (cur == e && next == s)
				continue;
			if (nCost < d[next]) {
				d[next] = nCost;
				pq.push({ nCost, next });
			}
		}
	}
	return d[N];	// mistake by d[e] as my habit
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		v[a].push_back({ cost, b });
		v[b].push_back({ cost, a });
	}
	int minDis = INF;
	int maxDis = 0;
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0, 1 });
	fill(d, d + MAX, INF);
	d[1] = 0;
	// first dijkstra, trace
	while (!pq.empty()) {
		int cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (d[cur] < cost)
			continue;
		for (auto i : v[cur]) {
			int nCost = i.first + cost;
			int next = i.second;
			if (nCost < d[next]) {
				d[next] = nCost;
				pq.push({ nCost, next });
				trace[next] = cur;
			}
		}
	}
	minDis = d[N];
	// trace road dijkstra (O(VElogV))
	for (int i = N; i != 1; i = trace[i]) {
		maxDis = max(maxDis, dijkstra(trace[i], i));
	}
	if (maxDis >= INF)
		cout << -1 << "\n";
	else
		cout << maxDis - minDis << "\n";
}
/*
6 6
1 2 3
2 3 3
3 4 3
4 5 3
5 6 3
1 6 18
ans: 3

3 3
1 2 3
2 3 3
1 3 12
ans : 3
*/