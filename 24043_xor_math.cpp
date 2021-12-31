// 220101 #24043 Good Bye BOJ 2021! E¹ø
// xor theory, math, dfs
// proof by ac...
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
const int MAX = 102;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e16;
const int MOD = 1e9 + 7;
int N, m, cnt;
bool vis[1 << 21];
vector<int> a, ans;
void dfs(int cur, int h) {
	if (h % 2 == 0) {
		ans.push_back(1);
		vis[cur ^ a[0]] = true;
		dfs(cur ^ a[0], h + 1);
	}
	else {
		for (int i = 0; i < N; i++) {
			if (!vis[cur ^ a[i]]) {
				ans.push_back(i + 1);
				vis[cur ^ a[i]] = true;
				dfs(cur ^ a[i], h + 1);
				break;
			}
		}
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	a.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	vis[0] = true;
	dfs(0, 0);
	cout << ans.size() << "\n";
	for (int i : ans)cout << i << "\n";
}