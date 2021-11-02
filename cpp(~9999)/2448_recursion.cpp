// 210122 #2448 º°Âï±â - 11 Gold IV
// recursion
#include <iostream>
#include <cstring>
using namespace std;
char a[3073][6145];
int N;
void solve(int n, int x, int y) {
	if (n==3) {
		a[y][x] = '*';

		a[y + 1][x - 1] = '*';
		a[y + 1][x + 1] = '*';

		a[y + 2][x - 2] = '*';
		a[y + 2][x - 1] = '*';
		a[y + 2][x] = '*';
		a[y + 2][x + 1] = '*';
		a[y + 2][x + 2] = '*';
		return;
	}
	solve(n / 2, x, y);
	solve(n / 2, x - n / 2, y + n / 2);
	// mid: ' ' (not *)
	solve(n / 2, x + n / 2, y + n / 2);
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	memset(a, ' ', sizeof(a));
	solve(N, N, 0);
	for (int i = 0; i < N; i++) {
		for (int j = 1; j < 2 * N; j++) {
			cout << a[i][j];
		}
		cout << "\n";
	}
}