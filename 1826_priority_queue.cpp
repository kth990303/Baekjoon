// 210606 #1826 연료 채우기 Gold III
// priority_queue O(lgN)
// bfs: O(N^2) -> TLE
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
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 10001;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
int N, L, P, ans;
vector<pi> v;
priority_queue<pi> pq;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
	}
	sort(all(v));
	cin >> L >> P;
	int i = 0, dis = P;
	while (dis < L) {
		while (i < N && v[i].first <= dis) {
			pq.push({ v[i].second, v[i].first });
			i++;
		}
		if (pq.empty()) {
			cout << -1 << "\n";
			return 0;
		}
		dis += pq.top().first;
		pq.pop();
		ans++;
	}
	cout << ans << "\n";
}