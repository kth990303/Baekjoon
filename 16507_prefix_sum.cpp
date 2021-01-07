// 210107 #16507 어두운 건 무서워 Silver I
// prefix_sum O(NQ): 112ms
#include <iostream>
using namespace std;
const int MAX = 1001;
int R, C, Q, a[MAX][MAX], s[MAX][MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> R >> C >> Q;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			cin >> a[i][j];
			// prefix_sum
			s[i][j] += s[i][j - 1] + a[i][j];
		}
	}
	while (Q--) {
		int r1, c1, r2, c2;
		cin >> r1 >> c1 >> r2 >> c2;
		int div = (r2 - r1 + 1) * (c2 - c1 + 1);
		int sum = 0;
		for (int i = r1; i <= r2; i++) {
			sum += s[i][c2] - s[i][c1 - 1];
		}
		sum /= div;
		cout << sum << "\n";
	}
}