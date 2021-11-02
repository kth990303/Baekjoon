// 210604 #1630 ¿À¹Î½Ä Gold IV
// math, eratosthenes sieve
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 1000001;
const int INF = 0x3f3f3f3f;
const int MOD = 987654321;
int N;
vector<int> prime;
bool isPrime[MAX];
void sieve() {
	fill(isPrime, isPrime + MAX, true);
	for (int i = 2; i*i <= N; i++) {
		if (!isPrime[i])
			continue;
		for (int j = i * 2; j <= N; j += i) {
			isPrime[j] = false;
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	sieve();
	for (int i = 2; i <= N; i++) {
		if (isPrime[i])
			prime.push_back(i);
	}
	ll ans = 1;
	for (auto i : prime) {
		double n1 = log2(N);
		double n2 = log2(i);
		ans *= pow(i, (int)(n1 / n2));
		ans %= MOD;
	}
	cout << ans << "\n";
}