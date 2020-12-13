// 201213 #1719 택배 Gold IV
// dijkstra + 경로추척 풀이
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
const int MAX = 201;
const int INF = 1e9 + 7;
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
	// dijkstra o(NlgM)
	// 총시간복잡도: O(N^2lgM)
	for (int i = 1; i <= N; i++) {
		int p[MAX];	// 경로 추적을 위한 배열
		priority_queue<pii, vector<pii>, greater<pii>> pq;
		fill(d, d + MAX, INF);
		pq.push({ 0, i });
		d[i] = 0;
		while (!pq.empty()) {
			int cost = pq.top().first;
			int cur = pq.top().second;
			pq.pop();
			if (d[cur] < cost)
				continue;
			for (auto k : v[cur]) {
				int next = k.second;
				int nCost = k.first + cost;
				if (nCost < d[next]) {
					d[next] = nCost;
					p[next] = cur;	// 결국은 최단경로들만 부모 배열에 저장됨.
					pq.push({ nCost, next });
				}
			}
		}
		for (int j = 1; j <= N; j++) {
			if (i == j) {
				cout << "- ";
				continue;
			}
			int ans = p[j];
			// 따라서 경로추적을 하면 
			// 최단경로일 때의 길이 추적됨.
			for (int k = j; k != i; k = p[k]) {
				ans = k;
			}
			cout << ans << " ";
		}
		cout << "\n";
	}
}