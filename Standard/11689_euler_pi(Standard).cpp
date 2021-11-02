// 210729 #11689 GCD(n, k)=1 Gold I
// Euler-pi function O(sqrt(N))
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;
const int MAX = 1000001;
ll N, n;
int isPrime[MAX];
vector<ll> v;
void sieve() {
	fill(isPrime, isPrime + MAX, true);
	for (int i = 2; i * i < MAX; i++) {
		if (!isPrime[i])
			continue;
		for (int j = i * 2; j < MAX; j += i) {
			isPrime[j] = false;
		}
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	sieve();
	n = N;
	for (ll i = 2; i * i <= n; i++) {
		if (N == 1)
			break;
		if (isPrime[i] && !(N % i)) {
			v.push_back(i);
			while (!(N % i))
				N /= i;
		}
	}
	if (N != 1)
		v.push_back(N);
	ll ans = n;
	for (auto i : v) {
		ans /= i;
		ans *= (i - 1);
	}
	cout << ans << "\n";
}