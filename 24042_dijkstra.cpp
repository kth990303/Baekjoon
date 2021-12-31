// 220101 #24042 Good Bye BOJ 2021! D¹ø
// dijkstra
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MAX = 100011;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e16;
const int MOD = 1e9 + 7;
ll N, M, d[MAX];
vector<pl> v[MAX];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		ll a, b;
		cin >> a >> b;
		v[a].push_back({ i, b });
		v[b].push_back({ i, a });
	}
	priority_queue<pl, vector<pl>, greater<pl>> pq;
	fill(d, d + MAX, LNF);
	d[1] = 0;
	pq.push({ 0, 1 });
	while (!pq.empty()) {
		ll cur = pq.top().second;
		ll time = pq.top().first;
		pq.pop();
		if (d[cur] < time)
			continue;
		if (cur == N) {
			cout << time;
			return 0;
		}
		for (auto i : v[cur]) {
			ll next = i.second;
			ll nTime = i.first + M * (time / M);
			while (nTime <= time)
				nTime += M;
			if (nTime < d[next]) {
				d[next] = nTime;
				pq.push({ nTime, next });
			}
		}
	}
}