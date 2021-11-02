// 210213 #2665 미로 만들기 Gold IV
// bfs + dp
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
const int MAX = 51;
const int INF = 0x7f7f7f;
int N, a[MAX][MAX];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int visit[MAX][MAX];	// visit memory can use dp table
void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
				if (visit[ny][nx] > visit[y][x] + !a[ny][nx]) {
					visit[ny][nx] = visit[y][x] + !a[ny][nx];
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
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			a[i][j] = s[j] - '0';
		}
	}
	memset(visit, INF, sizeof(visit));
	visit[0][0] = 0;
	bfs(0, 0);
	cout << visit[N - 1][N - 1] << "\n";
}