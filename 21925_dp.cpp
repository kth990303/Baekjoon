// 210801 #21925 Â¦¼ö ÆÓ¸°µå·Ò Gold III
// dp O(N)
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
const int MAX = 5001;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
int N, a[MAX], d[MAX], ans;
int flag(int s, int e) {
	if (s >= e || !((e - s) % 2))
		return 0;
	int s1 = s, e1 = e, flag = 1;
	while (s1 < e1) {
		if (a[s1] != a[e1]) {
			flag = 0;
			break;
		}
		s1++; e1--;
	}
	return flag;
}
int dp(int cur) {
	if (cur >= N)
		return 0;
	int& ret = d[cur];
	if (ret != -1)
		return ret;
	ret = flag(cur, N - 1);
	for (int i = cur + 1; i < N - 1; i += 2) {
		if (flag(cur, i) && dp(i + 1)) {
			ret = max(ret, dp(i + 1) + 1);
		}
	}
	return ret;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	memset(d, -1, sizeof(d));
	if (!dp(0))
		cout << -1 << "\n";
	else
		cout << dp(0) << "\n";
}