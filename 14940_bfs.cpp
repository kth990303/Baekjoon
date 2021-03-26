// 210326 #14940 쉬운 최단거리 Gold V
// simple bfs
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <queue>
#include <string>
using namespace std;
const int MAX = 1001;
const int INF = 1e9 + 7;
int N, M, a[MAX][MAX], d[MAX][MAX];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
bool visit[MAX][MAX];
void bfs(int x, int y) {
	queue<pair<int, pair<int, int>>> q;
	q.push({ 0, {x, y} });
	visit[y][x] = true;
	d[y][x] = 0;
	while (!q.empty()) {
		int dis = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
				if (!visit[ny][nx] && a[ny][nx]) {
					visit[ny][nx] = true;
					d[ny][nx] = dis + 1;
					q.push({ dis + 1, {nx, ny} });
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
	memset(d, -1, sizeof(d));
	int sx = 0, sy = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a[i][j];
			if (a[i][j] == 2) {
				sx = j;
				sy = i;
				d[i][j] = 0;
			}
			else if (!a[i][j])
				d[i][j] = 0;
		}
	}
	bfs(sx, sy);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << d[i][j] << " ";
		}
		cout << "\n";
	}
}