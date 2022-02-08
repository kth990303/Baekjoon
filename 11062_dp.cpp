// 220208 #11062 카드 게임 Gold III
// dp + game_theory
// O(N^2)
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
const int MAX = 1011;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e16;
const int MOD = 1e9 + 7;
int N, a[MAX], d[MAX][MAX][2];
int dp(int s,int e, int cnt) {
	if (s > e)return 0;
	if (s == e)return cnt?0:a[s];
	int& ret = d[s][e][cnt];
	if (~ret)return ret;
	ret = 0;
	if (cnt)
		ret = min(dp(s + 1, e, 0), dp(s, e - 1, 0));
	else
		ret = max(dp(s + 1, e, 1) + a[s], dp(s, e - 1, 1) + a[e]);
	return ret;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	int t;
	cin >> t;
	while (t--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> a[i];
		}
		memset(d, -1, sizeof(d));
		cout << dp(0, N - 1, 0) << "\n";
	}
}