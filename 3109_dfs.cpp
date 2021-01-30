// 210130 #3109 »§Áý Gold II
// dfs (like Gold IV ... why gold 2?) 
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 501;
const int MAX_R = 10001;
int dx[3] = { 1,1,1 };
int dy[3] = { -1,0,1 };
int R, C, ans;
char a[MAX_R][MAX];
bool visit[MAX_R][MAX], flag;
bool dfs(int x, int y) {
	if (x == C - 1) {
		flag = true;
		return true;
	}
	visit[y][x] = true;
	for (int i = 0; i < 3; i++) {
		if (flag)
			return true;
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < C && ny < R) {
			if (!visit[ny][nx] && a[ny][nx]=='.') {
				visit[ny][nx] = true;
				// function will proceed immediately anyway
				// therefore, no other compartment can visit
				dfs(nx, ny);
			}
		}
	}
	return flag;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < R; i++) {
		flag = false;
		if (dfs(0, i))
			ans++;
	}
	cout << ans << "\n";
}