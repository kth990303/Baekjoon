// 210730 #15897 잘못 구현한 에라토스테네스의 체 Gold II
// harmonic_lemma, math
// O(sqrt(N))
// UCPC2018 prelim
#include <iostream>
typedef long long ll;
using namespace std;
ll N;
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	ll j = 1, ans = N;
	for (ll i = 2; i < N; i = j + 1) {
		j = (N - 1) / ((N - 1) / i);
		ll cnt = 1 + (N - 1) / i;
		ans += (j - i + 1) * cnt;
	}
	if (N != 1)
		ans++;
	cout << ans << "\n";
}