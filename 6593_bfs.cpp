// 210722 #6593 »ó¹üºôµù Gold V
// I think it's Silver I (icpc.me/7569)
// typical bfs O(N^3)
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <cstring>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
const int MAX = 31;
const int INF = 0x3f3f3f3f;
int L, R, C, Sx, Sy, Sz;
int dx[6] = { 0,0,-1,1,0,0 };
int dy[6] = { -1,1,0,0,0,0 };
int dz[6] = { 0,0,0,0,-1,1 };
char a[MAX][MAX][MAX];
bool visit[MAX][MAX][MAX];
int bfs(int x, int y, int z) {
	queue<pair<pi, pi>> q;
	q.push({ { 0, z }, { x, y } });
	visit[z][y][x] = true;
	while (!q.empty()) {
		int time = q.front().first.first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		int z = q.front().first.second;
		q.pop();
		if (a[z][y][x] == 'E')
			return time;
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nz = z + dz[i];
			if (nx >= 0 && ny >= 0 && nz >= 0 && nx < C && ny < R && nz < L) {
				if (!visit[nz][ny][nx] && a[nz][ny][nx] != '#') {
					visit[nz][ny][nx] = true;
					q.push({ {time + 1, nz}, {nx, ny} });
				}
			}
		}
	}
	return -1;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	while (cin >> L >> R >> C) {
		if (!L && !R && !C)
			break;
		memset(visit, false, sizeof(visit));
		for (int k = 0; k < L; k++) {
			for (int i = 0; i < R; i++) {
				string s;
				cin >> s;
				for (int j = 0; j < C; j++) {
					a[k][i][j] = s[j];
					if (a[k][i][j] == 'S') {
						Sx = j, Sy = i, Sz = k;
					}
				}
			}
		}
		int ans = bfs(Sx, Sy, Sz);
		if (ans == -1)
			cout << "Trapped!\n";
		else
			cout << "Escaped in " << ans << " minute(s).\n";
	}
}