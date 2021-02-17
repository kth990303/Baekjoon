// 210218 #12100 2048(Easy) Gold II
// backtracking + implementation
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 21;
int a[MAX][MAX], b[5][MAX][MAX], N, ans;
bool used[MAX][MAX];
bool move(int cur) {
	bool flag = false;
	memset(used, false, sizeof(used));
	if (cur == 0) {
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int k = 0;
				while (i - k - 1 >= 0) {
					if (!used[i - k - 1][j] && a[i][j] && a[i - k - 1][j] == a[i][j]) {
						flag = true;
						a[i - k - 1][j] *= 2;
						a[i][j] = 0;
						used[i - k - 1][j] = true;
						break;
					}
					else if (!a[i - k - 1][j])
						k++;
					else break;
				}
			}
		}
		for (int i = 1; i < N; i++) {
			for (int j = 0; j < N; j++) {
				int k = 0;
				while (1) {
					if (i - k >= 1 && a[i - k][j] && !a[i - k - 1][j]) {
						a[i - k - 1][j] = a[i - k][j];
						a[i - k][j] = 0;
						k++;
					}
					else
						break;
				}
			}
		}
	}
	else if (cur == 1) {
		for (int i = N - 2; i >= 0; i--) {
			for (int j = 0; j < N; j++) {
				int k = 0;
				while (i + k + 1 < N) {
					if (!used[i + k + 1][j] && a[i][j] && a[i + k + 1][j] == a[i][j]) {
						flag = true;
						a[i + k + 1][j] *= 2;
						a[i][j] = 0;
						used[i + k + 1][j] = true;
						break;
					}
					else if (!a[i + k + 1][j])
						k++;
					else break;
				}
			}
		}
		for (int i = N - 2; i >= 0; i--) {
			for (int j = 0; j < N; j++) {
				int k = 0;
				while (1) {
					if (i + k < N - 1 && a[i + k][j] && !a[i + k + 1][j]) {
						a[i + k + 1][j] = a[i + k][j];
						a[i + k][j] = 0;
						k++;
					}
					else
						break;
				}
			}
		}
	}
	else if (cur == 2) {
		for (int i = 0; i < N; i++) {
			for (int j = 1; j < N; j++) {
				int k = 0;
				while (j - k - 1 >= 0) {
					if (!used[i][j - k - 1] && a[i][j] && a[i][j - k - 1] == a[i][j]) {
						flag = true;
						a[i][j - k - 1] *= 2;
						a[i][j] = 0;
						used[i][j - k - 1] = true;
						break;
					}
					else if (!a[i][j - k - 1])
						k++;
					else break;
				}

			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 1; j < N; j++) {
				int k = 0;
				while (1) {
					if (j - k >= 1 && a[i][j - k] && !a[i][j - k - 1]) {
						a[i][j - k - 1] = a[i][j - k];
						a[i][j - k] = 0;
						k++;
					}
					else
						break;
				}
			}
		}
	}
	else {
		for (int i = 0; i < N; i++) {
			for (int j = N - 2; j >= 0; j--) {
				int k = 0;
				while (j + k + 1 < N) {
					if (!used[i][j + k + 1] && a[i][j] && a[i][j + k + 1] == a[i][j]) {
						flag = true;
						a[i][j + k + 1] *= 2;
						a[i][j] = 0;
						used[i][j + k + 1] = true;
						break;
					}
					else if (!a[i][j + k + 1])
						k++;
					else break;
				}

			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = N - 2; j >= 0; j--) {
				int k = 0;
				while (1) {
					if (j + k < N - 1 && a[i][j + k] && !a[i][j + k + 1]) {
						a[i][j + k + 1] = a[i][j + k];
						a[i][j + k] = 0;
						k++;
					}
					else
						break;
				}
			}
		}
	}
	return flag;
}
void check(int n) {
	if (n == 5) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				ans = max(ans, a[i][j]);
			}
		}
		return;
	}
	for (int i = 0; i < 4; i++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				b[n][i][j] = a[i][j];
			}
		}
		move(i);
		check(n + 1);
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				a[i][j] = b[n][i][j];
			}
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
		}
	}
	check(0);
	cout << ans << "\n";
}