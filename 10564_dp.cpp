// 210722 #10564 ∆»±¡«Ù∆Ï±‚ Gold II
// dp + prefix_sum
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
const int MAX = 5001;
const int INF = 0x3f3f3f3f;
int N, M, d[MAX][201];
vector<int> v;
int dp(int cur, int n) {
	if (cur <= 0)
		return !cur ? 0 : -INF;
	int& ret = d[cur][n];
	if (ret != -1)
		return ret;
	ret = -INF;
	for (int i = 0; i < v.size(); i++) {
		ret = max(ret, dp(cur - n * v[i], n + 1) + v[i]);
	}
	return ret;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	int t;
	cin >> t;
	while (t--) {
		v.clear();
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			int n;
			cin >> n;
			v.push_back(n);
		}
		memset(d, -1, sizeof(d));
		int ans = dp(N, 1);
		if (ans < 0)
			cout << -1 << "\n";
		else
			cout << ans << "\n";
	}
}