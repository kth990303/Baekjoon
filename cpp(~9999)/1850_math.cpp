// 210116 #1850 최대공약수 Silver II
// Euclidean
#include <iostream>
using namespace std;
typedef long long ll;
ll N, M;
ll gcd(ll a, ll b) {
	ll r = a % b;
	if (!r) return b;
	return gcd(b, r);
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	ll k = gcd(N, M);
	for (int i = 0; i < k; i++) {
		cout << 1;
	}
}