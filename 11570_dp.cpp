// 211215 #11570 È¯»óÀÇµà¿§ Platinum V
// top-down is easier than bottom-up
// bipartite graph? -> No, before answer inflences next answer
// dp O(N^2) I think it's G2~G1
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
const int MAX = 2011;
const int INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
ll N, a[MAX], d[MAX][MAX];
ll dp(int n1, int n2) {
	if (n1 >= N || n2 >= N)return 0;
	ll& ret = d[n1][n2];
	if (ret != -1)
		return ret;
	ret = LNF;
	int cur = max(n1, n2) + 1;
	ret = min({ ret, dp(cur, n2) + (n1 ? abs(a[cur] - a[n1]) : 0),
		dp(n1, cur) + (n2 ? abs(a[cur] - a[n2]) : 0) });
	return ret;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	memset(d, -1, sizeof(d));
	cout << dp(0, 0) << "\n";
}