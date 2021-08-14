// 210814 #4924 Á¤¼ö·Ð½È¾î Platinum V
// sieve + prefix_sum O((U-L)*tc)
#include <iostream>
#include <vector>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
const int MAX = 1000001;
int L, U, a[MAX], p[MAX], M[MAX], m[MAX];
bool isPrime[MAX];
vector<int> prime;
void sieve() {
	fill(isPrime, isPrime + MAX, true);
	isPrime[0] = isPrime[1] = false;
	for (int i = 2; i * i < MAX; i++) {
		if (!isPrime[i])
			continue;
		for (int j = i * 2; j < MAX; j += i)
			isPrime[j] = false;
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	sieve();
	for (int i = 2; i < MAX; i++) {
		if (isPrime[i]) {
			a[i] = -1;
			prime.push_back(i);
			continue;
		}
		int n = i;
		for (auto j : prime) {
			if (n == 1)
				break;
			if (isPrime[n]) {
				a[i]++;
				break;
			}
			if (!(n % j)) {
				while (!(n % j)) {
					n /= j;
					a[i]++;
				}
			}
		}
	}
	for (int i = 1; i < MAX; i++) {
		a[i]--;
		p[i] = p[i - 1] + a[i];
	}
	for (int i = 1;; i++) {
		cin >> L >> U;
		if (L == -1 && U == -1)
			break;
		int N1 = -2e9, N2 = p[L - 1];
		int ans = a[L];
		for (int j = L+1; j <= U; j++) {
			N1 = p[j];
			N2 = min(p[j - 1], N2);
			ans = max(N1 - N2, ans);
		}
		cout << i << ". " << ans << "\n";
	}
}