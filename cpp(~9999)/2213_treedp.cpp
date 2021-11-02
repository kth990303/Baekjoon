// 211003 #2213 트리의 독립집합 Gold I
// treeDP
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
const int MAX = 10011;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
int N, a[MAX], d[MAX][2];
vector<int> v[MAX], c[MAX], res;
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
int dp(int cur, int flag) {
	int& ret = d[cur][flag];
	if (ret != -1)
		return ret;
	ret = 0;
	for (auto i : c[cur]) {
		int tmp = dp(i, 0);
		if (!flag)
			tmp = max(tmp, dp(i, 1));
		ret += tmp;
	}
	if (flag)
		ret += a[cur];
	return ret;
}
void trace(int cur, int prev = -1) {
	if (d[cur][1] > d[cur][0] && !visit[prev]) {
		res.push_back(cur);
		visit[cur] = true;
	}
	for (auto i : c[cur]) {
		if (i != prev)
			trace(i, cur);
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < N - 1; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		v[n1].push_back(n2);
		v[n2].push_back(n1);
	}
	init(1);
	memset(d, -1, sizeof(d));
	int ans = max(dp(1, 0), dp(1, 1));
	cout << ans << "\n";
	fill(visit, visit + MAX, false);
	trace(1);
	sort(all(res));
	for (auto i : res)
		cout << i << " ";
}