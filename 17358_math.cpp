// 17358 º¹ºÒº¹À¸·Î Áö±¸ ¸ê¸Á Silver V
// combination
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
const int MAX = 500001;
ll N, d[MAX / 2] = { 0,1,3, };
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	N /= 2;
	for (ll i = 3; i <= N; i++) {
		// except myself
		d[i] = ((2*i-1) * d[i - 1]) % MOD;
	}
	cout << d[N] << "\n";
}