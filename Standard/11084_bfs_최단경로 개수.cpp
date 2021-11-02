// 200903 #11084 나이트의 염탐 Gold II
// 최단경로의 "개수", 나이트의 거지같은 이동반경
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const int MAX = 401;
const ll MOD = 1000000009;
int dx[8] = { -2,-1,1,2,-2,-1,1,2 };
int dy[8] = { -1,-2,-2,-1,1,2,2,1 };
bool visit[MAX][MAX];
pii d[MAX][MAX];	// first:거리 , second:가지 수
int r, c;
void bfs(int x, int y) {
	queue<pii> q;
	q.push({ x,y });
	visit[y][x] = true;
	d[y][x].second = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < c && ny < r) {
				// 방문하지 않은 곳이면
				if (!visit[ny][nx]) {
					// 경우의 수가 당연히 증가하고
					d[ny][nx].second += d[y][x].second;
					d[ny][nx].second %= MOD;
					// q에 삽입해서 여기서부터 진행
					q.push({ nx, ny });
					visit[ny][nx] = true;
					d[ny][nx].first = d[y][x].first + 1;
				}
				// 방문했는데 이동 가능한 경우인 곳이면
				// 같은 목적지를 다른 길로 온 경우이므로
				// 여태까지의 경로의 경우의 수를 더해줌.
				else if (d[ny][nx].first == d[y][x].first + 1) {
					d[ny][nx].second += d[y][x].second;
					d[ny][nx].second %= MOD;
				}
			}
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> r >> c;
	bfs(0, 0);
	if (!d[r-1][c-1].second)
		cout << "None\n";
	else {
		cout << d[r-1][c-1].first << " " << d[r-1][c-1].second << "\n";
	}
}