// 210920 #20549 ¿Œ¥ˆ¿Ã¿« ∞ÌπŒ Gold I
// bitmasking + dijkstra
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
const int INF = 0x3f3f3f3f;
struct Point {
	int x, y, cost, flag;
};
struct cmp {
	bool operator() (Point p1, Point p2) {
		return p1.cost > p2.cost;
	}
};
int N, A, B, C, Sx, Sy, M, a[MAX][MAX], ans, d[MAX][MAX][1 << 4];
vector<pii> v[MAX][MAX];
int dx[16] = { 0,0,-1,1,-1,1,-1,1,-2,-1,1,2,-2,-1,1,2 };
int dy[16] = { -1,1,0,0,-1,-1,1,1,-1,-2,-2,-1,1,2,2,1 };
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> A >> B >> C >> Sy >> Sx >> M;
	for (int i = 1; i <= M; i++) {
		int x, y;
		cin >> y >> x;
		a[y][x] = i;
	}
	priority_queue<Point, vector<Point>, cmp> pq;
	pq.push({ Sx, Sy, 0, 0 });
	memset(d, INF, sizeof(d));
	d[Sy][Sx][0] = 0;
	while (!pq.empty()) {
		int x = pq.top().x;
		int y = pq.top().y;
		int cost = pq.top().cost;
		int flag = pq.top().flag;
		pq.pop();
		if (flag == (1 << M) - 1) {
			cout << cost << "\n";
			return 0;
		}
		if (d[y][x][flag] < cost)
			continue;
		for (int i = 0; i < 4; i++) {
			int l = 1;
			while (1) {
				int nx = x + dx[i] * l;
				int ny = y + dy[i] * l;
				int nCost = cost + C;
				if (nx < 0 || ny < 0 || nx >= N || ny >= N)
					break;
				if (a[ny][nx] && !(flag & (1 << (a[ny][nx] - 1)))) {
					int nFlag = flag | (1 << (a[ny][nx] - 1));
					if (nCost < d[ny][nx][nFlag]) {
						d[ny][nx][nFlag] = nCost;
						pq.push({ nx, ny, nCost, nFlag });
					}
				}
				else if (nCost < d[ny][nx][flag]) {
					d[ny][nx][flag] = nCost;
					pq.push({ nx, ny, nCost, flag });
				}
				l++;
			}
		}
		for (int i = 4; i < 8; i++) {
			int l = 1;
			while (1) {
				int nx = x + dx[i] * l;
				int ny = y + dy[i] * l;
				int nCost = cost + B;
				if (nx < 0 || ny < 0 || nx >= N || ny >= N)
					break;
				if (a[ny][nx] && !(flag & (1 << (a[ny][nx] - 1)))) {
					int nFlag = flag | (1 << (a[ny][nx] - 1));
					if (nCost < d[ny][nx][nFlag]) {
						d[ny][nx][nFlag] = nCost;
						pq.push({ nx, ny, nCost, nFlag });
					}
				}
				else if (nCost < d[ny][nx][flag]) {
					d[ny][nx][flag] = nCost;
					pq.push({ nx, ny, nCost, flag });
				}
				l++;
			}
		}
		for (int i = 8; i < 16; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nCost = cost + A;
			if (nx < 0 || ny < 0 || nx >= N || ny >= N)
				continue;
			if (a[ny][nx] && !(flag & (1 << (a[ny][nx] - 1)))) {
				int nFlag = flag | (1 << (a[ny][nx] - 1));
				if (nCost < d[ny][nx][nFlag]) {
					d[ny][nx][nFlag] = nCost;
					pq.push({ nx, ny, nCost, nFlag });
				}
			}
			else if (nCost < d[ny][nx][flag]) {
				d[ny][nx][flag] = nCost;
				pq.push({ nx, ny, nCost, flag });
			}
		}
	}
}