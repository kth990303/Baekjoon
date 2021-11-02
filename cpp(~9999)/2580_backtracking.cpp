// 210218 #2580 ½ºµµÄí Gold IV
// backtracking
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 9;
int a[MAX][MAX];
bool row[MAX][MAX+1], col[MAX][MAX+1], square[3][3][MAX+1];
void solve(int n) {
	if (n == 81) {
		for (int i = 0; i < MAX; i++) {
			for (int j = 0; j < MAX; j++) {
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}
	int p = n / 9, q = n % 9;
	if (a[p][q])
		solve(n + 1);
	else {
		for (int i = 1; i <= 9; i++) {
			if (!row[p][i] && !col[q][i] && !square[p / 3][q / 3][i]) {
				a[p][q] = i;
				row[p][i] = true;
				col[q][i] = true;
				square[p / 3][q / 3][i] = true;
				solve(n + 1);
				a[p][q] = 0;
				row[p][i] = false;
				col[q][i] = false;
				square[p / 3][q / 3][i] = false;
			}
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			cin >> a[i][j];
			row[i][a[i][j]] = true;
			col[j][a[i][j]] = true;
			square[i/3][j/3][a[i][j]] = true;
		}
	}
	solve(0);
}