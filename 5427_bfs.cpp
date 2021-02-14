// 210214 #5427 불 Gold IV
// BFS + 삼성 sw역량테스트 추천문제 + 구현
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
const int MAX = 1001;
// 나의 좌표
struct Point {
	int x, y;
};
Point me;
// 불 좌표 모음
vector<Point> fire;
int H, W, ans, ntime = -1;
bool flag = true;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
char a[MAX][MAX];
bool visit[MAX][MAX];
queue<pair<int, int>> q2;
// 불의 이동
void bfs2() {
	int num = fire.size();
	// 처음엔 불이 num개만 존재하며,
	// 굳이 queue를 쓰지 않고 이동만 하면 됨
	for (int i = 0; i < num; i++) {
		int x = fire[i].x;
		int y = fire[i].y;
		for (int j = 0; j < 4; j++) {
			int nx = x + dx[j];
			int ny = y + dy[j];
			if (nx >= 0 && ny >= 0 && nx < W && ny < H) {
				// 불일 경우 그냥 visit처리 시켜버림
				// 그리고 .인 경우만 불이 이동가능함
				// 처음엔 if(a[ny][nx]!='#')으로만 했는데 MLE...
				if (!visit[ny][nx] && a[ny][nx] == '.') {
					a[ny][nx] = '*';
					visit[ny][nx] = true;
					fire.push_back({ nx, ny });
				}
			}
		}
	}
	// 이제 불의 개수는 늘어남.
	num = fire.size();
}
// 탈출하기 위한 나 자신의 bfs
void bfs(int x, int y) {
	queue<pair<pair<int, int>, int>> q;
	q.push({ { x, y }, 0 });
	visit[y][x] = true;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int time = q.front().second;
		q.pop();
		// 이동 시간이 증가하기 시작했으면
		// 불 이동시키고 탐색 시작
		if (ntime < time) {
			ntime = time;
			bfs2();
		}
		/*
		cout << "\n";
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cout << a[i][j];
			}
			cout << "\n";
		}*/
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < W && ny < H) {
				if (!visit[ny][nx]) {
					if (a[ny][nx] == '.') {
						visit[ny][nx] = true;
						q.push({ {nx, ny}, time + 1 });
					}
				}
			}
			// 가장자리에 있는 경우
			// 탈출하면 되므로 time+1을 리턴해줌
			else {
				flag = true;
				ans = time + 1;
				return;
			}
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		ntime = -1;
		flag = false;
		ans = 0;
		memset(a, false, sizeof(a));
		memset(visit, false, sizeof(visit));
		fire.clear();
		cin >> W >> H;
		for (int i = 0; i < H; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < W; j++) {
				a[i][j] = s[j];
				if (a[i][j] == '@') {
					me.y = i;
					me.x = j;
				}
				// 벽인 경우 어차피 이동 못하므로 visit처리 함
				else if (a[i][j] == '#') {
					visit[i][j] = true;
				}
				// 불인 경우 어차피 이동못하므로 visit처리 함
				else if (a[i][j] == '*') {
					visit[i][j] = true;
					fire.push_back({ j, i });
				}
			}
		}
		bfs(me.x, me.y);
		if (flag)
			cout << ans << "\n";
		else
			cout << "IMPOSSIBLE" << "\n";
	}
}