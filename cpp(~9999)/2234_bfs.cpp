// 210915 #2234 ¼º°û Gold IV
// bfs, bitmask O(4NM*NM))
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
const int MAX = 51;
int a[MAX][MAX], N, M, S;
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,-1,0,1 };
bool visit[MAX][MAX];
void bfs(int x, int y) {
	queue<pi> q;
	q.push({ x, y });
	visit[y][x] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (a[y][x] & (1 << i))
				continue;
			if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
				if (!visit[ny][nx]) {
					visit[ny][nx] = true;
					S++;
					q.push({ nx, ny });
				}
			}
		}
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	swap(N, M);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a[i][j];
		}
	}
	int cnt = 0, res = 0, ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visit[i][j]) {
				S = 1;
				cnt++;
				bfs(j, i);
				res = max(res, S);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < 4; k++) {
				int nx = j + dx[k];
				int ny = i + dy[k];
				if (nx>=0 && ny>=0 && nx<M && ny<N && a[i][j] & (1 << k)) {
					a[i][j] &= ~(1 << k);
					memset(visit, false, sizeof(visit));
					S = 1;
					bfs(j, i);
					ans = max(ans, S);
					a[i][j] |= (1 << k);
				}
			}
		}
	}
	cout << cnt << "\n" << res << "\n" << ans << "\n";
}