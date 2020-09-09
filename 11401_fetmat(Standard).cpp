// 200909 #11401 이항계수3 Gold I
// 페르마의 소정리, 분할정복 이용
// 메모리를 훨씬 아끼는 풀이
#include <iostream>
using namespace std;
typedef long long ll;
const int MAX = 4000001;
const ll MOD = 1000000007;
ll N, K;	// 따로 펙토리얼을 메모이제이션하지 않음
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
	ll A = 1, B = 1;
	// N! 계산
	for (int i = 1; i <= N; i++) {
		A *= (ll)i;
		A %= MOD;
	}
	// K!(N-K)! 계산
	for (int i = 1; i <= K; i++) {
		B *= (ll)i;
		B %= MOD;
	}
	for (int i = 1; i <= N - K; i++) {
		B *= (ll)i;
		B %= MOD;
	}
	// B는 페르마 소정리에 의해 (n-k)!k!의 p-2제곱
	// B^(p-2)%p = 1/B %p 이므로
	B = fpow(B, MOD - 2);
	ll ans = (A * B) % MOD;
	cout << ans << "\n";
}