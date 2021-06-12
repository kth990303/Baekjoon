// 210612 #17216 가장 큰 감소부분수열 Silver I
// boj.kr/11722
// LDS (Longest Decreasing Sequence)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 1001;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int N, ans, d[MAX];
vector<int> v;
int dp(int cur) {
	if (cur >= N)
		return 0;
	int& ret = d[cur];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = cur + 1; i < N; i++) {
		if (v[cur] <= v[i])
			continue;
		ret = max(ret, dp(i));
	}
	return ret += v[cur];
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	memset(d, -1, sizeof(d));
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans = max(ans, dp(i));
	}
	cout << ans << "\n";
}