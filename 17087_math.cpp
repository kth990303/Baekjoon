// 210123 #17087 ¼û¹Ù²ÀÁú6 Silver I
// I think this problem: Silver III ~ Silver II
// Euclidean, Number_theory
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100001;
int N, S, a[MAX], n[MAX];
// euclidean
int gcd(int a, int b) {
	int r = a % b;
	if (!r)
		return b;
	return gcd(b, r);
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		n[i] = abs(S - a[i]);
	}
	int tmp = n[0], ans = n[0];
	// maximum gcd
	for (int i = 1; i < N; i++) {
		ans = min(ans, gcd(tmp, n[i]));
	}
	cout << ans << "\n";
}