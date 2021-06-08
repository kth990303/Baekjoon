// 210608 #12784 인하니카 공화국 Gold III
// dfs
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 1001;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int N, M;
vector<pi> v[MAX];
bool visit[MAX];
int dfs(int cur) {
	visit[cur] = true;
	int ret = 0;
	bool flag = false;
	for (auto i : v[cur]) {
		int cost = i.first;
		if (!visit[i.second]) {
			ret += min(cost, dfs(i.second));
			flag = true;
		}
	}
	return flag ? ret : INF;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		for (auto& i : v) {
			i.clear();
		}
		fill(visit, visit + MAX, false);
		cin >> N >> M;
		if (N == 1) {
			cout << 0 << "\n";
			continue;
		}
		for (int i = 0; i < M; i++) {
			int a, b, cost;
			cin >> a >> b >> cost;
			v[a].push_back({ cost, b });
			v[b].push_back({ cost, a });
		}
		cout << dfs(1) << "\n";
	}
}