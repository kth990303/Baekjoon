#include <iostream>
using namespace std;
typedef long long ll;
const int MAX = 4000001;
const ll MOD = 1000000007;
ll N, K, d[MAX] = { 1, };
ll fpow(ll val, ll idx) {
	ll ret = 1;
	while (idx > 0) {
		if (idx % 2) {
			ret *= val;
			ret %= MOD;
		}
		val *= val;
		val %= MOD;
		idx /= 2;
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		d[i] = ((ll)i * d[i - 1]) % MOD;
	}
	ll A = d[N];
	ll B = (d[N - K] * d[K]) % MOD;
	// B는 페르마 소정리에 의해 (n-k)!k!의 p-2제곱
	B = fpow(B, MOD - 2);
	ll ans = (A * B) % MOD;
	cout << ans << "\n";
}