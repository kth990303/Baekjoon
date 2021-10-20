// 211020 #1800 인터넷 설치 Gold I
// dijkstra + binary_search?
// possible? possible? Ssab-Possible
// if cost>mid ? cost=1 : cost=0 
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 1011;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
int N, P, K, d[MAX], ans = -1;
vector<pi> v[MAX];
int dijkstra(int price) {
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	fill(d, d + MAX, INF);
	d[1] = 0;
	pq.push({ 0,1 });
	while (!pq.empty()) {
		int cur = pq.top().second;
		int cost = pq.top().first;
		pq.pop();
		if (d[cur] < cost)
			continue;
		if (cur == N)
			return d[N];
		for (auto i : v[cur]) {
			int next = i.second;
			int nCost = i.first;
			nCost > price ? nCost = cost + 1 : nCost = cost;
			if (nCost < d[next]) {
				d[next] = nCost;
				pq.push({ nCost, next });
			}
		}
	}
	return d[N];
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> P >> K;
	for (int i = 0; i < P; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		v[a].push_back({cost, b});
		v[b].push_back({ cost, a });
	}
	int s = 0, e = 1e6;
	while (s <= e) {
		int mid = (s + e) / 2;
		int n = dijkstra(mid);
		if (n <= K) {
			ans = mid;
			e = mid - 1;
		}
		else
			s = mid + 1;
	}
	cout << ans << "\n";
}