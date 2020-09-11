// 200911 #15966 군계일학 Silver II
// LIS 느낌나지만, 1 더해지는 거므로 좀 더 무난히 가능
// 하지만, 난 여기서도 헤맸다...
// 바텀업 방식
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100001;
const int VAL_MAX = 1000002;
int N, a[MAX], cache[VAL_MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	fill(cache, cache + MAX, -1);
	int ans = 1;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		if (cache[a[i] - 1] == -1) {
			cache[a[i]] = 1;
		}
		else {
			cache[a[i]] = cache[a[i] - 1] + 1;
			ans = max(ans, cache[a[i]]);
		}
	}
	cout << ans << "\n";
}