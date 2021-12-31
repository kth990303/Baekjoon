// 220101 #24039 Good Bye BOJ 2021! A¹ø
// sieve, number_theory
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MAX = 10011;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e16;
const int MOD = 1e9 + 7;
int N, M;
string s;
vector<int> prime;
bool isPrime[MAX], ans[MAX*MAX];
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
	prime.push_back(2);
	for (int i = 3; i <= 10000; i += 2) {
		if (isPrime[i])
			prime.push_back(i);
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	eratosthenes();
	for (int i = 0; i < prime.size()-1; i++) {
		ans[prime[i] * prime[i + 1]] = true;
	}
	for (int i = N + 1;; i++) {
		if (ans[i]) {
			cout << i;
			return 0;
		}
	}
}