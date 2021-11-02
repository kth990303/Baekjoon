// 210124 #1407 2로 몇 번 나누어질까 Gold IV
// Math
#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
ll A, B, ans;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> A >> B;
	ll same = 0;
	for (ll i = 60; i >= 0; i--) {
		ll k = (1LL << i);
		// Number of multipliers
		// A=k*a, B=k*b
		// k(b)-k*(A-1) (k(b-a+1))
		ll num = (B / k) - ((A - (ll)1) / k);
		if (num) {
			ans += (num-same) * k;
			same = num;	// exclude duplicates
		}

	}
	cout << ans << "\n";
}