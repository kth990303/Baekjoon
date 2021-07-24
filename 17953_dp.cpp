// 210724 #17953 µðÀúÆ® Gold V
// dp
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
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 100001;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
int N, M, b[11][MAX], a[MAX][11], d[MAX][11];
int dp(int cur, int n) {
	if (cur >= N)
		return 0;
	int& ret = d[cur][n];
	if (ret != -1)
		return ret;
	ret = 0;
	ret = dp(cur + 1, n) + (a[cur][n] / 2);
	for (int i = 0; i < M; i++) {
		if (i == n)
			continue;
		ret = max(ret, dp(cur + 1, i) + a[cur][i]);
	}
	return ret;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			cin >> b[i][j];
		}
	}
	for (int i = 0; i < M; i++) {
		for (int j = 0; j < N; j++) {
			a[j][i] = b[i][j];
		}
	}
	memset(d, -1, sizeof(d));
	int ans = 0;
	for (int i = 0; i < M; i++) {
		ans = max(ans, dp(1, i) + a[0][i]);
	}
	cout << ans << "\n";
}