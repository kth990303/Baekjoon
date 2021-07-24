// 210724 #17942 알고리즘공부 Gold II
// greedy+priority_queue+graph
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
typedef pair<ll, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 100001;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
ll N, M, R, a[MAX], ans;
vector<pi> v[MAX];
bool visit[MAX];
priority_queue<pi, vector<pi>, greater<pi>> pq;
void dfs(int cur) {
	for (auto i : v[cur]) {
		if (visit[i.second])
			continue;
		a[i.second] -= i.first;
		pq.push({ a[i.second], i.second });
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	ll s = 0, e = 0;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		pq.push({ a[i], i });
		s = max(s, a[i]);
		e += a[i];
	}
	cin >> R;
	while (R--) {
		int n1, n2;
		ll d;
		cin >> n1 >> n2 >> d;
		n1--; n2--;
		v[n1].push_back({ d, n2 });
	}
	int cnt = 0;
	while (cnt < M) {
		int cur = pq.top().second;
		ll cost = pq.top().first;
		pq.pop();
		if (visit[cur])
			continue;
		visit[cur] = true;
		dfs(cur);
		ans = max(ans, cost);
		cnt++;
	}
	cout << ans << "\n";
}