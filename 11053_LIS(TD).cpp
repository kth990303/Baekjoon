// 200911 #11053 LIS 1 Silver II
// 탑다운 방식으로 해결 (종만북)
// O(N^2)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 1001;
int N, a[MAX];
int cache[MAX];
int dp(int s) {
	int& ret = cache[s];
	if (ret != -1)
		return ret;
	ret = 1;
	for (int i = s + 1; i < N; i++) {
		if (a[s] < a[i]) {
			ret = max(ret, dp(i) + 1);
		}
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	fill(cache, cache + MAX, -1);
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans = max(ans, dp(i));
	}
	cout << ans << "\n";
}