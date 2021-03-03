// 210303 #2573 ºù»ê Gold IV
// DFS(or bfs) + impl
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
typedef pair<int, int> pi;
const int MAX = 301;
int N, M, a[MAX][MAX], tmp[MAX][MAX];
bool visit[MAX][MAX], comp;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
vector<pi> v;
// check ice component cnt is only 1
void check(int x, int y) {
	visit[y][x] = true;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
			if (!visit[ny][nx] && a[ny][nx]) {
				visit[ny][nx] = true;
				check(nx, ny);
			}
		}
	}
}
// melting ice
void dfs() {
	for (auto cur : v) {
		int x = cur.first;
		int y = cur.second;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
				if (!a[ny][nx]) {
					// why tmp?
					// because melted ice shouldn't affect other ice
					tmp[y][x]--;
					tmp[y][x] = max(tmp[y][x], 0);
				}
			}
		}
	}
	// ice list
	v.clear();
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (tmp[i][j])
				v.push_back({ j, i });
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a[i][j];
			if (a[i][j]) {
				v.push_back({ j, i });
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tmp[i][j] = a[i][j];
		}
	}
	int ans = 0;
	while (1) {
		// if no ice, ans=0
		bool noIce = true;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				if (a[i][j])
					noIce = false;
			}
		}
		if (noIce) {
			cout << 0 << "\n";
			return 0;
		}
		// check ice component
		memset(visit, false, sizeof(visit));
		check(v[0].first, v[0].second);
		for (auto i : v) {
			if (!visit[i.second][i.first]) {
				comp = true;
				break;
			}
		}
		// if ice component cnt>1
		if (comp) {
			cout << ans << "\n";
			return 0;
		}
		// melting ice
		dfs();
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				a[i][j] = tmp[i][j];
			}
		}
		ans++;
	}
}