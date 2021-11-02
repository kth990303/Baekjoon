// 201213 #2589 보물섬 Gold V
// 가장 먼 두개의 점? 어떻게 해야 할까?
// TLE는 나지 않을까? -> O(N^4) -> O(6*10^6)
// 모든 'L'에서 bfs를 돌리면 됨~
#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
const int MAX = 51;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int N, M;
char a[MAX][MAX];
int d[MAX][MAX], ans;
bool visit[MAX][MAX];
int bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visit[y][x] = true;
	int ret = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
				if (!visit[ny][nx] && a[ny][nx] == 'L') {
					q.push({ nx, ny });
					visit[ny][nx] = true;
					d[ny][nx] = d[y][x] + 1;
					ret = max(ret, d[ny][nx]);
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

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a[i][j];
		}
	}
	// for문에서 O(N^2)
	// bfs에서 O(N^2)
	// N이 50이므로 시간초과 걱정은 할 필요가 없다.
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			memset(visit, false, sizeof(visit));
			memset(d, false, sizeof(d));
			if(a[i][j]=='L')
				ans = max(ans, bfs(j, i));
		}
	}
	cout << ans << "\n";
}