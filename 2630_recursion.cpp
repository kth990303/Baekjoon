// 210213 #2630 색종이 만들기 Silver III
// recursion
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 129;
int N, a[MAX][MAX], w, b;
void solve(int x, int y, int dx, int dy) {
	bool flag = true;
	for (int i = y; i < y + dy; i++) {
		for (int j = x; j < x + dx; j++) {
			if (a[i][j] != a[y][x])
				flag = false;
		}
	}
	if (flag || (dx==1 && dy==1)) {
		if (a[y][x] == 1)
			b++;
		else
			w++;
		return;
	}
	else {
		solve(x, y, dx / 2, dy / 2);
		solve(x + dx / 2, y, dx / 2, dy / 2);
		solve(x, y + dy / 2, dx / 2, dy / 2);
		solve(x + dx / 2, y + dy / 2, dx / 2, dy / 2);
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
	solve(0, 0, N, N);
	cout << w << "\n" << b << "\n";
}