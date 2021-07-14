// 210714 #22114 창영이와 점프 Silver II
// O(N*2)
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pi;
const int MAX = 100001;
int N, K, a[MAX], d[MAX][2];
// O(N*2)
int dp(int cur, int flag) {
	if (cur >= N - 1)
		return 0;
	int& ret = d[cur][flag];
	if (ret != -1)
		return ret;
	ret = 0;
	if (a[cur] <= K)
		ret = max(ret, dp(cur + 1, flag) + 1);
	else if (a[cur] > K && !flag)
		ret = max(ret, dp(cur + 1, 1) + 1);
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 0; i < N - 1; i++) {
		cin >> a[i];
	}
	memset(d, -1, sizeof(d));
	int ans = 0;
	// not O(N*N*2) because no memset
	for (int i = 0; i < N; i++) {
		ans = max(ans, dp(i, 0));
	}
	cout << ans + 1 << "\n";
}