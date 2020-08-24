// 200824 #1194 달이 차오른다, 가자. Gold I
// 미친문제.... 난이도 미쳤어....
// bfs(최단경로)+bitmask+구현
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
char a[51][51];
int visit[51][51][1<<7];	// 111111
// 열쇠에 따라 방문여부의 상태를 다르게 해야됨!
// 그렇게 안할 경우, 열쇠 얻은 후 다시 되돌아가질 못함
// boolean 느낌의 상태 체크 -> bitmask
// 이 방문여부가 이 문제의 핵심
int ans;
int bfs(int x, int y, int k) {
	queue<pair<pair<int, int>, int>> q;
	q.push({ { x,y }, k });
	visit[y][x][k] = 1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int k = q.front().second;
		q.pop();
		if (a[y][x] == '1') {
			return visit[y][x][k] - 1;
		}
		// bfs 실행
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
				if (!visit[ny][nx][k]) {
					if (a[ny][nx] == '#')
						continue;
					if (a[ny][nx] >= 'a' && a[ny][nx] <= 'f') {
						int nk = k | (1 << (a[ny][nx] - 'a'));
						visit[ny][nx][nk] = visit[y][x][k] + 1;
						//a[ny][nx] = '.';
						//이 주석부분은 아직도 아리까리하네...
						//열쇠를 잡은 상태 nk로 해야되니까!
						q.push({ { nx, ny }, nk });
					}
					else if (a[ny][nx] >= 'A' && a[ny][nx] <= 'F') {
						int nk = k & (1 << (a[ny][nx] - 'A'));
						// 비트마스크 초보면 nk==1으로 하다가 낭패봄
						// 100000, 010000 등의 경우가 있잖아...
						if (nk!=0) {
							visit[ny][nx][k] = visit[y][x][k] + 1;
							q.push({ { nx, ny }, k });
						}
						else
							continue;
					}
					else {
						visit[ny][nx][k] = visit[y][x][k] + 1;
						q.push({ { nx, ny }, k });
					}
				}
			}
		}
	}
	return -1;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> a[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (a[i][j] == '0')
				ans = bfs(j, i, 0);
		}
	}
	if (ans == 0)
		cout << -1;
	else
		cout << ans;
}