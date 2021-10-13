// 211013 #23237 How Many Subtrees? Gold IV
// treedp
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
const int MAX = 12;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e16;
const ll MOD = 1e9 + 7;
vector<int> v[MAX], c[MAX];
int t, N, ans, d[MAX];
bool visit[MAX];
void init(int cur) {
	visit[cur] = true;
	for (auto i : v[cur]) {
		if (!visit[i]) {
			c[cur].push_back(i);
			init(i);
		}
	}
}
int dp(int cur, int prev) {
	int& ret = d[cur];
	if (ret != -1)
		return ret;
	ret = 1;
	for (auto i : c[cur]) {
		ret *= (1 + dp(i, cur));
	}
	return ret;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	while (cin >> N && N) {
		ans = 0;
		fill(d, d + MAX, 0);
		fill(visit, visit + MAX, false);
		for (int i = 0; i < N; i++) {
			v[i].clear();
			c[i].clear();
		}
		for (int i = 0; i < N - 1; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		init(0);
		memset(d, -1, sizeof(d));
		for (int i = 0; i < N; i++)
			ans += dp(i, -1);
		cout << "Case " << ++t << ": " << ans << "\n";
	}
}