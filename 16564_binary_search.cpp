// 210119 #16564 히오스 프로게이머 Silver I
// Binary_search O(NlgK)
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 1000001;
ll a[MAX], d[MAX], N, K, ans;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	ll s = 0, e = 2000000000;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	while (s <= e) {
		ll mid = (s + e) / 2, sum = 0;
		// O(N)
		for (int i = 0; i < N; i++) {
			sum += max(mid - a[i], (ll)0);
		}
		if (sum > K)
			e = mid - 1;
		else {
			ans = mid;
			s = mid + 1;
		}
	}
	cout << ans << "\n";
}