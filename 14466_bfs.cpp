// 211020 #14466 소가 길을 건너간 이유6 Gold IV
// this solution is harder than best solution
// bfs
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 205;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
int N, K, R, a[MAX][MAX], ans, res;
vector<int> v;
bool visit[MAX][MAX];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
void bfs(int sx, int sy) {
	queue<pi> q;
	visit[sy][sx] = true;
	q.push({ sx, sy });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		if (a[y][x] == 1 && (sx != x || sy != y))
			res++;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (!(nx % 2) && !(ny % 2))
				continue;
			if (nx > 0 && ny > 0 && nx < N && ny < N) {
				if (!visit[ny][nx] && a[ny][nx] != -1) {
					visit[ny][nx] = true;
					q.push({ nx, ny });
				}
			}
		}
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> K >> R;
	for (int i = 0; i < R; i++) {
		int y1, x1, y2, x2;
		cin >> y1 >> x1 >> y2 >> x2;
		y1 *= 2; x1 *= 2; y2 *= 2; x2 *= 2;
		y1--; x1--; y2--; x2--;
		a[(y1 + y2) / 2][(x1 + x2) / 2] = -1;
		visit[(y1 + y2) / 2][(x1 + x2) / 2] = true;
	}
	for (int i = 0; i < K; i++) {
		int x, y;
		cin >> y >> x;
		x *= 2; y *= 2;
		x--; y--;
		a[y][x] = 1;
	}
	N *= 2;
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < N; j++) {
			memset(visit, false, sizeof(visit));
			if (a[i][j] == 1 && !visit[i][j]) {
				res = 0;
				bfs(j, i);
				ans += res;
			}
		}
	}
	cout << K * (K - 1) / 2 - ans / 2 << "\n";
}