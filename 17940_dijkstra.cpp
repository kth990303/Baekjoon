// 210724 #17940 ¡ˆ«œ√∂ Gold II
// dijkstra
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
typedef pair<pi, int> pii;
typedef pair<ll, ll> pl;
const int MAX = 1001;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
int N, M;
ll p[MAX], a[MAX][MAX], d[MAX];
vector<pii> v[MAX];
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> p[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
			if (a[i][j]) {
				if (p[i] == p[j])
					v[i].push_back({ {0, a[i][j]},j });
				else
					v[i].push_back({ {1, a[i][j]},j });
			}
		}
	}
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ {0, 0}, 0 });
	fill(d, d + MAX, LNF);
	d[0] = 0;
	while (!pq.empty()) {
		ll time = pq.top().first.first;
		ll cost = pq.top().first.second;
		int cur = pq.top().second;
		pq.pop();
		if (d[cur] < time * 1e10 + cost)
			continue;
		for (auto i : v[cur]) {
			int next = i.second;
			ll nCost = i.first.second + cost;
			ll nTime = i.first.first + time;
			if (nTime * 1e10 + nCost < d[next]) {
				d[next] = nTime * 1e10 + nCost;
				pq.push({ {nTime, nCost}, next });
			}
		}
	}
	ll ans = d[M];
	cout << d[M] / (ll)(1e10) << " " << d[M] % (ll)(1e10) << "\n";
}