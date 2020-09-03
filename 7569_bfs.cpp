// 200904 토마토 #7569 Silver I
// 개인적으론 골드5라고 생각함
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 101;
const int LMAX = 10001;
int N, M, H;	// 세로, 가로, 높이
int dx[6] = { 0,0,-1,1,0,0 };
int dy[6] = { -1,1,0,0,-1,1 };
int a[LMAX][MAX];
bool visit[LMAX][MAX];
queue<pair<pair<int, int>, int>> q;
int bfs() {
	int ret = 0;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int day = q.front().second;
		ret = max(day, ret);
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i];
			int ny;
			if (i < 4)
				ny = y + dy[i];
			else
				ny = y + dy[i] * N;
			if (nx >= 0 && ny >= 0 && nx < M && ny < N*H) {
				if (i<4 && (ny / N) != (y / N))
					continue;
				if (!visit[ny][nx] && !a[ny][nx]) {
					a[ny][nx] = 1;
					visit[ny][nx] = true;
					q.push({ {nx, ny}, day + 1 });
				}
			}
		}
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> M >> N >> H;
	for (int i = 0; i < N * H; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a[i][j];
		}
	}
	bool flag = true;
	int ans = 0;
	for (int i = 0; i < N * H; i++) {
		for (int j = 0; j < M; j++) {
			if (!visit[i][j] && a[i][j] == 1) {
				q.push({ {j,i}, 0 });
				visit[i][j] = true;
			}
		}
	}
	ans = bfs();
	for (int i = 0; i < N * H; i++) {
		for (int j = 0; j < M; j++) {
			if (!a[i][j]) {
				flag = false;
			}
		}
	}
	if (!flag)
		cout << -1 << "\n";
	else
		cout << ans << "\n";
}