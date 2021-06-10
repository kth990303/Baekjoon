// 210610 #17143 ³¬½Ã¿Õ Gold II
// implementation
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <cmath>
#include <map>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 101;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
bool cmp(pi p1, pi p2) {
	return p1.first > p2.first;
}
struct Fish {
	int r, c, s, d, z;
};
int dx[5] = { 0,0,0,1,-1 };
int dy[5] = { 0,-1,1,0,0 };
int R, C, M, a[MAX][MAX], ans;
vector<Fish> v;
bool visit[10001];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> R >> C >> M;
	v.resize(M);
	memset(a, -1, sizeof(a));
	for (int i = 0; i < M; i++) {
		cin >> v[i].r >> v[i].c >> v[i].s >> v[i].d >> v[i].z;
		a[v[i].r][v[i].c] = i;
	}
	for (int j = 1; j <= C; j++) {
		vector<pi> m[MAX][MAX];
		// fishing
		for (int i = 1; i <= R; i++) {
			if (a[i][j] != -1) {
				ans += v[a[i][j]].z;
				visit[a[i][j]] = true;
				a[i][j] = -1;
				break;
			}
		}
		// moving
		for (int i = 0; i < v.size(); i++) {
			if (visit[i])
				continue;
			int y = v[i].r;
			int x = v[i].c;
			int nx, ny, dis;
			if (v[i].d == 1) {
				dis = v[i].s % (2 * (R - 1));
				nx = x;
				ny = y + dy[v[i].d] * dis;
				// array index
				if (ny < 1) {
					v[i].d = 2;
					ny = 2 - ny;
				}
				if (ny > R) {
					v[i].d = 1;
					ny = 2 * R - ny;
				}
			}
			else if (v[i].d == 2) {
				dis = v[i].s % (2 * (R - 1));
				nx = x;
				ny = y + dy[v[i].d] * dis;
				if (ny > R) {
					v[i].d = 1;
					ny = 2 * R - ny;
				}
				if (ny < 1) {
					v[i].d = 2;
					ny = 2 - ny;
				}
			}
			else if (v[i].d == 3) {
				dis = v[i].s % (2 * (C - 1));
				nx = x + dx[v[i].d] * dis;
				ny = y;
				if (nx>C) {
					v[i].d = 4;
					nx = 2 * C - nx;
				}
				if (nx < 1) {
					v[i].d = 3;
					nx = 2 - nx;
				}
			}
			else {
				dis = v[i].s % (2 * (C - 1));
				nx = x + dx[v[i].d] * dis;
				ny = y;
				if (nx < 1) {
					v[i].d = 3;
					nx = 2 - nx;
				}
				if (nx > C) {
					v[i].d = 4;
					nx = 2 * C - nx;
				}
			}
			m[ny][nx].push_back({ v[i].z, i });
			a[y][x] = -1;
			v[i].r = ny;
			v[i].c = nx;
		}
		fill(visit, visit + 10001, true);
		// eat fish
		for (int i1 = 1; i1 <= R; i1++) {
			for (int j1 = 1; j1 <= C; j1++) {
				if (!m[i1][j1].size())
					continue;
				else if (m[i1][j1].size() == 1) {
					int idx = m[i1][j1][0].second;
					a[v[idx].r][v[idx].c] = idx;
					visit[idx] = false;
				}
				else {
					// sort bigger
					sort(all(m[i1][j1]), cmp);
					int idx = m[i1][j1][0].second;
					a[v[idx].r][v[idx].c] = idx;
					visit[idx] = false;
				}
			}
		}
	}
	cout << ans << "\n";
}