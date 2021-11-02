// 210120 #1041 ¡÷ªÁ¿ß Silver I
// greedy + math
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll N, a[6], ans;
ll min3() {
	return min({ a[0] + a[1] + a[2], a[0] + a[1] + a[3], a[0] + a[2] + a[4],
		a[0] + a[3] + a[4], a[1] + a[3] + a[5], a[5] + a[1] + a[2],
		a[5] + a[2] + a[4], a[5] + a[3] + a[4] });
}
ll min2() {
	return min({ a[0] + a[1], a[0] + a[2], a[0] + a[3], a[0] + a[4],
		a[1] + a[2], a[1] + a[3], a[1] + a[5], a[2] + a[4], a[2] + a[5],
		a[3] + a[4], a[3] + a[5], a[4] + a[5] });
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	ll min1 = 51, max1 = 0, sum = 0;
	for (int i = 0; i < 6; i++) {
		cin >> a[i];
		min1 = min(min1, a[i]);
		max1 = max(max1, a[i]);
		sum += a[i];
	}
	// exception case
	if (N == 1) {
		cout << sum - max1 << "\n";
		return 0;
	}
	ans += (ll)4 * min3();
	ans += (ll)(8 * N - 12) * min2();
	ans += (N - 2) * (5 * N - 6) * min1;
	cout << ans << "\n";
}