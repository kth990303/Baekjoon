// 210116 #2436 °ø¾à¼ö Gold V
// number_theory : euclidean
#include <iostream>
using namespace std;
int N, M;
int gcd(int a, int b) {
	int r = a % b;
	if (!r) return b;
	return gcd(b, r);
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	// lcm factorization -> min(sum) is answer.
	int k = M / N, idx = 1;
	for (int i = 2; i * i < k; i++) {
		if (!(k % i)) {
			// if this is not, 1 24 => 4 6
			if (gcd(i, k / i) == 1)
				idx = i;
		}
	}
	cout << N * idx << " " << N * (k / idx) << "\n";
}