// 200903 #14554 The Other Way Gold I
// dijkstra+최단경로 개수
// 각각 가중치가 다를 때 최단경로 개수
// 유사한 문제: 11084 (단, 가중치가 존재하지 않음)
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
const int MAX = 100001;
const ll MOD = 1000000009;
const ll INF = 1e18;
vector<pll> v[MAX];
pll d[MAX];
int N, M, S, E;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M >> S >> E;
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ c,b });
		v[b].push_back({ c,a });
	}
	for (int i = 1; i <= N; i++) {
		d[i].first = INF;
	}
	priority_queue<pll, vector<pll>, greater<pll>> pq;
	d[S].first = 0;
	d[S].second = 1;
	pq.push({ 0, S });
	while (!pq.empty()) {
		ll cost = pq.top().first;
		int cur = pq.top().second;
		pq.pop();
		if (d[cur].first < cost)
			continue;
		for (auto i : v[cur]) {
			int next = i.second;
			ll nCost = i.first + cost;
			if (d[next].first > nCost) {
				d[next].first = nCost;
				pq.push({ nCost, next });
				d[next].second = d[cur].second;
			}
			// 방문했던 곳인데, 거리가 같다면
			// 같은 목적지를 다른 방면으로 방문했다는 소리
			// 이 외에는 다익스트라랑 같다
			else if (d[next].first == nCost) {
				d[next].second += d[cur].second;
				d[next].second %= MOD;
			}
		}
	}
	cout << d[E].second << "\n";
}