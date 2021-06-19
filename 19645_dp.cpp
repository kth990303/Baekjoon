// 210619 #19645 ÇÜÃÖ¸î? Gold I
// 0-1 knapsack O(850*850*N)
// backtracking: TLE -> knapsack memoization
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
const int MAX = 51;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int N, a[MAX], d[MAX][851][851], M, ans = INF;
int dp(int cur, int n1, int n2) {
	if (cur >= N)
		return min({ n1, n2, M - n1 - n2 });
	int& ret = d[cur][n1][n2];
	if (ret != -1)
		return ret;
	ret = dp(cur + 1, n1, n2);
	if (n1 + a[cur] <= 850)
		ret = max(ret, dp(cur + 1, n1 + a[cur], n2));
	if (n2 + a[cur] <= 850)
		ret = max(ret, dp(cur + 1, n1, n2 + a[cur]));
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		M += a[i];
	}
	memset(d, -1, sizeof(d));
	cout << dp(0, 0, 0) << "\n";
}