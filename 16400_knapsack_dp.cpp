// 200913 #16400 소수 화폐 Gold V
// O(N*소수개수+NlogN) -> O(N)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 40002;
const int MOD = 123456789;
vector<int> prime;
bool isPrime[MAX];
int N, d[MAX] = { 1, };
void eratosthenes() {
	fill(isPrime, isPrime + MAX, true);
	// 에라토스테네스 체로 소수 모음
	for (int i = 2; i * i < MAX; i++) {
		// 소수가 아닐 경우 진행하지 않고
		if (!isPrime[i])
			continue;
		// 소수의 배수인 것들은 false로
		for (int j = i * 2; j < MAX; j += i) {
			isPrime[j] = false;
		}
	}
	// N보다 작거나 같은 소수들로만 모음
	for (int i = 2; i <= N; i++) {
		if (isPrime[i])
			prime.push_back(i);
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	eratosthenes();
	// 각 금액마다 메모이제이션해주는 냅색 dp
	for (int i = 0; i < prime.size(); i++) {
		for (int j = prime[i]; j <= N; j++) {
			d[j] += d[j - prime[i]];
			d[j] %= MOD;
		}
	}
	cout << d[N] << "\n";
}