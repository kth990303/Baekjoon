// 200903 #14554 The Other Way Gold I
// dijkstra+�ִܰ�� ����
// ���� ����ġ�� �ٸ� �� �ִܰ�� ����
// ������ ����: 11084 (��, ����ġ�� �������� ����)
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
			// �湮�ߴ� ���ε�, �Ÿ��� ���ٸ�
			// ���� �������� �ٸ� ������� �湮�ߴٴ� �Ҹ�
			// �� �ܿ��� ���ͽ�Ʈ��� ����
			else if (d[next].first == nCost) {
				d[next].second += d[cur].second;
				d[next].second %= MOD;
			}
		}
	}
	cout << d[E].second << "\n";
}