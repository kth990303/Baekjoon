#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>
using namespace std;
const int MAX = 102;
typedef pair<int, pair<int, int>> pii;
int N, M;
char a[MAX][MAX];
bool visit[MAX][MAX];
int d[3][MAX][MAX];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int status = 0;
struct Person {
	int x, y;
};
Person p[2];
void bfs(int x, int y) {
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	memset(visit, false, sizeof(visit));
	pq.push({ 0, {x, y} });
	visit[y][x] = true;
	while (!pq.empty()) {
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		int cost = pq.top().first;
		pq.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
				if (!visit[ny][nx] && a[ny][nx] != '*') {
					d[status][ny][nx] = d[status][y][x];
					if (a[ny][nx] == '#')
						d[status][ny][nx]++;
					int nCost = d[status][ny][nx];
					visit[ny][nx] = true;
					pq.push({ nCost, {nx, ny} });
				}
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
		memset(visit, false, sizeof(visit));
		memset(d, 0, sizeof(d));
		memset(a, 0, sizeof(a));
		status = 0;
		int cnt = 0;
		cin >> N >> M;
		for (int i = 0; i <= M + 1; i++) {
			a[0][i] = '.';
			a[N + 1][i] = '.';
		}
		for (int i = 1; i <= N; i++) {
			a[i][0] = a[i][M + 1] = '.';
			for (int j = 1; j <= M; j++) {
				cin >> a[i][j];
				if (a[i][j] == '$') {
					p[cnt].x = j;
					p[cnt++].y = i;
				}
			}
		}
		N += 2;
		M += 2;
		bfs(0, 0);
		status++;
		bfs(p[0].x, p[0].y);
		status++;
		bfs(p[1].x, p[1].y);
		int ans = N * M;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (a[i][j] == '*')
					continue;
				int res = d[0][i][j] + d[1][i][j] + d[2][i][j];
				if (a[i][j] == '#')
					res -= 2;
				ans = min(ans, res);
			}
		}
		cout << ans << "\n";
	}
}