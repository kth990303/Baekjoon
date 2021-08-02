// 210730 #4355 ¼­·Î¼Ò Gold I
// Euler_pi (Standard)
// O(sqrt(N))
#include <iostream>
using namespace std;
const int MAX = 100001;
int N;
bool isPrime[MAX];
void sieve() {
	fill(isPrime, isPrime + MAX, true);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i < MAX; i++) {
		if (!isPrime[i])
			continue;
		for (int j = i * 2; j < MAX; j += i) {
			isPrime[j] = false;
		}
	}
}
int solve() {
	int ret = N, n = N;
	for (int i = 2; i * i <= N; i++) {
		if (n == 1)
			break;
		if (isPrime[i] && !(n % i)) {
			while (!(n % i))
				n /= i;
			ret /= i;
			ret *= (i - 1);
		}
	}
	if (n != 1) {
		ret /= n; 
		ret *= (n - 1);
	}
	return ret;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	sieve();
	while (cin >> N && N) {
		if (N == 1) {
			cout << 0 << "\n";
			continue;
		}
		cout << solve() << "\n";
	}
}