// 210620 #1757 含形含形 Gold IV
// dp
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 10001;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int N, M, a[MAX], d[MAX][501];
int dp(int cur, int m) {
	if (cur == N)
		return !m ? 0 : -INF;
	// if cur>N: then cur==N: m>0
	// so return -INF
	if (cur > N)
		return -INF;
	int& ret = d[cur][m];
	if (ret != -1)
		return ret;
	ret = 0;
	if (!m)
		ret = max(dp(cur + 1, m), dp(cur + 1, m + 1) + a[cur]);
	else if (m == M)
		ret = dp(cur + m, 0);
	else
		ret = max(dp(cur + 1, m + 1) + a[cur], dp(cur + m, 0));
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	memset(d, -1, sizeof(d));
	cout << dp(0, 0) << "\n";
}