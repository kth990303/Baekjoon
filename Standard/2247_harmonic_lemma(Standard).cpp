// 210730 #2247 실질적 약수 Gold III
// harmonic lemma(Standard)
// https://ahgus89.github.io/algorithm/Harmonic-Lemma/
// math O(sqrt(N))
#include <iostream>
typedef long long ll;
using namespace std;
const ll MOD = 1e6;
ll N, ans;
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	ll j = 0;
	for (ll i = 1; i <= N; i = j + 1) {
		j = N / (N / i);
		ll n = N / i * (j - i + 1);
		ans += n * (i + j) / 2;
		ans %= MOD;
	}
	ans -= (N % MOD);
	ans += MOD;
	ans %= MOD;
	ans -= (N * (N + 1) / 2) % MOD;
	ans += 1;
	ans += MOD;
	cout << ans % MOD << "\n";
}