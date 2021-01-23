// 210123 #11502 세 개의 소수 문제 Silver III
// Bruth-force, Math(eratosthenes' sieve)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 1001;
bool prime[MAX];
vector<int> v;
void sieve() {
	fill(prime, prime + MAX, true);
	for (int i = 2; i * i < 1000; i++) {
		if (!prime[i])
			continue;
		for (int j = i * 2; j < 1000; j += i) {
			prime[j] = false;
		}
	}
}
// if this code in main, 
// break; break; break; -> longer code
void find(int num) {
	for (int i = 0; i < v.size(); i++) {
		for (int j = 0; j < v.size(); j++) {
			for (int k = 0; k < v.size(); k++) {
				if (v[i] + v[j] + v[k] == num) {
					cout << v[i] << " " << v[j] << " " << v[k] << "\n";
					return;
				}
			}
		}
	}
	cout << 0 << "\n";
	return;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	sieve();
	for (int i = 2; i < 1000; i++) {
		if (prime[i])
			v.push_back(i);
	}
	while (t--) {
		int N;
		cin >> N;
		find(N);
	}
}