// 210714 #22116 창영이와 퇴근 Gold IV
// bfs + binary_search O(N^2lg(1e9))
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef pair<int, int> pi;
const int MAX = 1001;
const int INF = 0x3f3f3f3f;
int N, a[MAX][MAX], ans = INF;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
bool visit[MAX][MAX];
bool bfs(int x, int y) {
	queue<pi> q;
	q.push({ x, y });
	visit[y][x] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (y == N - 1 && x == N - 1)
			return true;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
				if (!visit[ny][nx] && abs(a[ny][nx] - a[y][x]) <= ans) {
					visit[ny][nx] = true;
					q.push({ nx, ny });
				}
			}
		}
	}
	return false;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
		}
	}
	int s = 0, e = 1e9, res = INF;
	while (s <= e) {
		ans = (s + e) / 2;
		memset(visit, false, sizeof(visit));
		if (bfs(0, 0)) {
			res = ans;
			e = ans - 1;
		}
		else
			s = ans + 1;
	}
	cout << res << "\n";
	
}