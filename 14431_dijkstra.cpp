// 210716 #14431 소수마을 Gold III
// dijkstra + sieve
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll, int> pi;
const int MAX = 4003;
const int INF = 0x3f3f3f3f;
ld X1, Y1, X2, Y2;
vector<pair<ld, ld>> tmp;
vector<pi> v[MAX];
bool prime[9000];
int N, d[MAX];
ll getDis(ld x1, ld y1, ld x2, ld y2) {
	return (ll)sqrt((x1 - x2) * (x1 - x2) +
		(y1 - y2) * (y1 - y2));
}
void sieve() {
	fill(prime, prime + 9000, true);
	prime[0] = prime[1] = false;
	for (int i = 2; i * i <= 9000; i++) {
		if (!prime[i])
			continue;
		for (int j = i * 2; j <= 9000; j += i) {
			prime[j] = false;
		}
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> X1 >> Y1 >> X2 >> Y2 >> N;
	tmp.resize(N + 2);
	sieve();
	tmp[0] = { X1, Y1 };
	for (int i = 1; i <= N; i++) {
		cin >> tmp[i].first >> tmp[i].second;
	}
	tmp[N + 1] = { X2, Y2 };
	for (int i = 0; i < N + 2; i++) {
		for (int j = i + 1; j < N + 2; j++) {
			if (i == j)
				continue;
			ll dist = getDis(tmp[i].first, tmp[i].second,
				tmp[j].first, tmp[j].second);
			if (prime[dist]) {
				v[i].push_back({ dist, j });
				v[j].push_back({ dist, i });
			}
		}
	}
	priority_queue<pi, vector<pi>, greater<pi>> pq;
	pq.push({ 0, 0 });
	fill(d, d + MAX, INF);
	d[0] = 0;
	while (!pq.empty()) {
		int cur = pq.top().second;
		ll cost = pq.top().first;
		pq.pop();
		if (d[cur] < cost)
			continue;
		for (auto i : v[cur]) {
			int next = i.second;
			ll nCost = i.first + cost;
			if (nCost < d[next]) {
				d[next] = nCost;
				pq.push({ nCost, next });
			}
		}
	}
	if (d[N + 1] >= INF)
		cout << -1 << "\n";
	else
		cout << d[N + 1] << "\n";
}