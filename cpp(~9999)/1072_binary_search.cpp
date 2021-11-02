// 210508 #1072 ∞‘¿” Silver III
// binary_search
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll X, Y, Z, ans = -1;
ll solve(ll s, ll e) {
	while (s <= e) {
		ll mid = (s + e) / 2;
		if (100 * (Y + mid) / (X + mid) >= Z) {
			ans = mid;
			e = mid - 1;
		}
		else
			s = mid + 1;
	}
	return ans;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> X >> Y;
	Z = 100 * Y / X;
	Z++;
	cout << solve(0, X) << "\n";
}
