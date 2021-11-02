// 211024 #2638 ДЎБо Gold IV
// impl, bfs
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
const int MAX = 103;
const double INF = 0x3f3f3f3f;
const int LNF = 1e18;
const int MOD = 1e9 + 7;
int N, M, a[MAX][MAX], ans, num;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
bool visit[MAX][MAX];
void innerCheck(int x, int y) {
	memset(visit, false, sizeof(visit));
	queue<pi> q;
	q.push({ x, y });
	visit[y][x] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		a[y][x] = 0;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
				if (!visit[ny][nx] && (!a[ny][nx]||a[ny][nx]==3)) {
					visit[ny][nx] = true;
					q.push({ nx, ny });
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visit[i][j] && !a[i][j]) {
				a[i][j] = 3;
			}
		}
	}
}
void melt() {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (a[i][j] != 1)
				continue;
			int cnt = 0;
			for (int k = 0; k < 4; k++) {
				int nx = j + dx[k];
				int ny = i + dy[k];
				if (nx >= 0 && ny >= 0 && nx < M && ny < N && !a[ny][nx])
					cnt++;
			}
			if (cnt >= 2)
				a[i][j] = 2;
		}
	}
	ans++;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (a[i][j] == 2) {
				a[i][j] = 0;
				num--;
			}
		}
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a[i][j];
			num += a[i][j];
		}
	}
	while (num) {
		bool flag = false;
		for (int i = 0; i < N; i++) {
			if (!a[i][0]) {
				innerCheck(0, i);
				flag = true;
				break;
			}
			if (!a[i][M - 1]) {
				innerCheck(M - 1, i);
				flag = true;
				break;
			}
		}
		for (int i = 0; i < M; i++) {
			if (flag) break;
			if (!a[0][i]) {
				innerCheck(i, 0);
				break;
			}
			if (!a[N - 1][i]) {
				innerCheck(i, N - 1);
				break;
			}
		}
		melt();
	}
	cout << ans << "\n";
}