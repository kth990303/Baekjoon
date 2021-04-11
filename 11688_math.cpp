// 210411 #11688 최소공배수 찾기 Gold IV
// math: euclidean, eratosthenes_sieve
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int MAX = 1000001;
ll a, b, L;
bool isPrime[MAX];
vector<int> v;
void sieve(ll num) {
	fill(isPrime, isPrime + MAX, true);
	for (int i = 2; i*i <= num; i++) {
		if (!isPrime[i])
			continue;
		for (int j = i * 2; j <= num; j += i) {
			isPrime[j] = false;
		}
	}
}
ll gcd(ll a, ll b) {
	ll r = a % b;
	if (!r)
		return b;
	return gcd(b, r);
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> a >> b >> L;
	ll k = gcd(a, b);
	ll n = (a / k) * (b / k) * k;
	if (L % n) {
		cout << -1 << "\n";
		return 0;
	}
	ll num = L / n;
	sieve(num);
	while (num != 1) {
		for (int i = 2; i <= num; i++) {
			if (num == 1)
				break;
			if (isPrime[i] && !(num % i)) {
				v.push_back(i);
				num /= i;
			}
		}
	}
	ll ans = 1;
	for (auto i : v) {
		while (!(L % i)) {
			ans *= i;
			L /= i;
		}
	}
	cout << ans << "\n";
}