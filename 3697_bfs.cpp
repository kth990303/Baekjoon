// 210520 #3697 Á¤»ó Platinum III
// not bfs N^2 time
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <queue>
using namespace std;
typedef pair<int, pair<int, int>> pi;
const int MAX = 501;
const int INF = 0x3f3f3f3f;
int a[MAX][MAX], N, M, D;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int visit[MAX][MAX];
vector<pi> v;
bool cmp(pi p1, pi p2) {
	return p1.first > p2.first;
}
int bfs(int h, int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	int cnt = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (a[y][x] > h)
			return 0;
		if (a[y][x] == h)
			cnt++;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
				if (visit[ny][nx] > visit[y][x])
					return 0;
				if (visit[ny][nx]!=visit[y][x] && a[ny][nx] > h - D) {
					visit[ny][nx] = visit[y][x];
					q.push({ nx, ny });
				}
			}
		}
	}
	return cnt;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		memset(visit, false, sizeof(visit));
		v.clear();
		cin >> N >> M >> D;
		int H = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				cin >> a[i][j];
				H = max(H, a[i][j]);
				v.push_back({ a[i][j], {j, i} });
			}
		}
		sort(v.begin(), v.end(), cmp);
		int ans = 0;
		for (int i = 0; i < v.size(); i++) {
			if (v[i].first == H) {
				ans++;
				continue;
			}
			if (v[i].first < D)
				break;
			int x = v[i].second.first;
			int y = v[i].second.second;
			if (visit[y][x])
				continue;
			visit[y][x] = v.size() - i;
			ans += bfs(v[i].first, x, y);
		}
		cout << ans << "\n";
	}
}