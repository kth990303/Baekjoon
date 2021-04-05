// 210405 #14499 주사위 굴리기 Gold IV
// impl rolling dice is difficult
// but not very difficult, and other things are easy
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 21;
int dx[4] = { 0,1,-1,0 };
int dy[4] = { 1,0,0,-1 };
int N, M, a[MAX][MAX], d[4][4], x, y, K, tmp[4];
int roll(int ch) {
	if (ch == 1) {
		tmp[0] = d[0][0]; tmp[1] = d[1][1];
		tmp[2] = d[2][0]; tmp[3] = d[3][1];

		d[0][0] = tmp[3]; d[1][1] = tmp[0];
		d[2][0] = tmp[1]; d[3][1] = tmp[2];
	}
	else if (ch == 2) {
		tmp[0] = d[0][0]; tmp[1] = d[1][1];
		tmp[2] = d[2][0]; tmp[3] = d[3][1];

		d[0][0] = tmp[1]; d[1][1] = tmp[2];
		d[2][0] = tmp[3]; d[3][1] = tmp[0];
	}
	else if (ch == 3) {
		for (int i = 0; i < 4; i++) {
			tmp[i] = d[i][0];
		}
		for (int i = 0; i < 4; i++) {
			d[i][0] = tmp[(i + 5) % 4];
		}
	}
	else if (ch == 0) {
		for (int i = 0; i < 4; i++) {
			tmp[i] = d[i][0];
		}
		for (int i = 0; i < 4; i++) {
			d[i][0] = tmp[(i + 3) % 4];
		}
	}

	if (!a[y][x])
		a[y][x] = d[0][0];
	else {
		d[0][0] = a[y][x];
		a[y][x] = 0;
	}
	return d[2][0];
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M >> y >> x >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a[i][j];
		}
	}
	while (K--) {
		int ch;
		cin >> ch;
		ch %= 4;
		int nx = x + dx[ch];
		int ny = y + dy[ch];
		if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
			x = nx; y = ny;
			cout << roll(ch) << "\n";
		}
	}

}