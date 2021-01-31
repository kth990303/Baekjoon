// 210131 #1941 ¼Ò¹®³­ Ä¥°øÁÖ(Ä¥¾Ç´ç....) Gold III
// Only backtracking? There are more than two directions!
// 25C7 -> check -> one clear? Yes? cnt++
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 6;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
char a[MAX][MAX];
int ans;
bool visit[MAX][MAX];
bool visit2[MAX][MAX];
void check(int x, int y) {
	visit2[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < 5 && ny < 5) {
			if (visit[ny][nx] && !visit2[ny][nx]) {
				visit2[ny][nx] = true;
				check(nx, ny);
			}
		}
	}
}
void select(int x, int y, int num, int cntS) {
	if (num == 7 && cntS >= 4) {
		int cnt = 0;
		for (int i = 0; i < 5; i++) {
			for (int j = 0; j < 5; j++) {
				if (visit[i][j] && !visit2[i][j]) {
					cnt++;
					check(j, i);
				}
			}
		}
		memset(visit2, false, sizeof(visit2));
		if (cnt == 1)
			ans++;
		return;
	}
	else if (num - cntS > 3)
		return;
	for (int i = y; i < 5; i++) {
		for (int j = x; j < 5; j++) {
			if (!visit[i][j]) {
				visit[i][j] = true;
				if (a[i][j] == 'S')
					select(j, i, num + 1, cntS + 1);
				else
					select(j, i, num + 1, cntS);
				visit[i][j] = false;
			}
		}
		x = 0;
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	for (int i = 0; i < 5; i++) {
		cin >> a[i];
	}
	select(0, 0, 0, 0);
	cout << ans << "\n";
}