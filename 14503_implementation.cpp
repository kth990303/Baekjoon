// 210112 #14503 ·Îº¿ Ã»¼Ò±â Gold V
// implementation + dfs
#include <iostream>
#include <algorithm>
#include <queue>
const int MAX = 51;
using namespace std;
int N, M, a[MAX][MAX], d, r, c, ans;
// north west south east
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
bool visit[MAX][MAX], flag;	// visit: clean area
void dfs(int x, int y, int dir) {
	visit[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int k = (i + dir + 1) % 4;
		int nx = x + dx[k];
		int ny = y + dy[k];
		if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
			if (!a[ny][nx] && !visit[ny][nx]) {
				visit[ny][nx] = true;
				// direction is k
				dfs(nx, ny, k);
				if (flag)
					return;
			}
		}
	}
	// fuckin fuck fuck!!! back
	int k = (dir + 2) % 4;
	if (!a[y + dy[k]][x + dx[k]]) {
		dfs(x + dx[k], y + dy[k], dir);
	}
	// if back is wall
	else {
		flag = true;
		return;
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M >> r >> c >> d;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a[i][j];
		}
	}
	// east, west change
	if (d == 1)
		d = 3;
	else if (d == 3)
		d = 1;
	dfs(c, r, d);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (visit[i][j])
				ans++;
		}
	}
	cout << ans << "\n";
}