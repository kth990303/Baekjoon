#include <iostream>
#include <vector>
using namespace std;
const int MAX = 7368788;
vector<int> prime;
bool isPrime[MAX];
int N;
void eratosthenes() {
	fill(isPrime, isPrime + MAX, true);
	// O(NlogN)
	for (int i = 2; i * i < MAX; i++) {
		if (!isPrime[i])
			continue;
		for (int j = i * 2; j < MAX; j += i) {
			isPrime[j] = false;
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	eratosthenes();
	int i = 2;
	while (prime.size() < N) {
		if (isPrime[i])
			prime.push_back(i);
		i++;
	}
	cout << prime[N - 1] << "\n";
}