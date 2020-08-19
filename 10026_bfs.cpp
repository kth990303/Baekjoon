// 200819 #10026 Gold V
// bfs 또는 dfs 이용
// 그래 이게 골5지, 다른 건 골5 치고 어려워
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
int dx[4] = { 0,0,-1,1 };	// 상하좌우
int dy[4] = { -1,1,0,0 };
bool visit[100][100];
char a[100][100];	// 정상
char b[100][100];	// R=G
int N, acnt = 0, bcnt = 0;	// 정상, 적록색약
// R!=G
void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visit[y][x] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
				if (!visit[ny][nx] && a[ny][nx] == a[y][x]) {
					visit[ny][nx] = true;
					q.push({ nx, ny });
				}
			}
		}
	}
}
// R=G
void bfs2(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y });
	visit[y][x] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
				// 다른 건 여기 뿐
				if (!visit[ny][nx]&&b[ny][nx]==b[y][x]) {
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

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	// 적록색약은 G랑 R이랑 같으므로 G를 R로 바꿈
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (a[i][j] == 'G')
				b[i][j] = 'R';
			else
				b[i][j] = a[i][j];
		}
	}
	// 방문하지 않은 곳 있으면 마저 탐색
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j]) {
				acnt++;
				bfs(j, i);
			}
		}
	}
	// 다시 visit배열 원래대로
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			visit[i][j] = false;
		}
	}
	// 이제 적록색약 구역 탐색 가자
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!visit[i][j]) {
				bcnt++;
				bfs2(j, i);
			}
		}
	}
	cout << acnt << " " << bcnt;
}