// 210509 #21736 헌내기는 친구가 필요해 Silver II
// bfs
#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
using namespace std;
const int MAX = 601;
int N, M, sx, sy, ans;
char a[MAX][MAX];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
bool visit[MAX][MAX];
void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visit[y][x] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (a[y][x] == 'P')
			ans++;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
				if (!visit[ny][nx] && a[ny][nx] != 'X') {
					visit[ny][nx] = true;
					q.push({ nx, ny });
				}
			}
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			a[i][j] = s[j];
			if (a[i][j] == 'I') {
				sy = i, sx = j;
			}
		}
	}
	bfs(sx, sy);
	if (!ans)
		cout << "TT\n";
	else
		cout << ans << "\n";
}