// 210326 #1799 ºñ¼ó Gold II
// backtracking O(2^(N/2*N/2))
// diagonal -> we can reduce time complexity
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
const int MAX = 11;
const int INF = 1e9 + 7;
int N, a[MAX][MAX], ans1, ans2, cnt;
int visit[MAX][MAX];
vector<pair<int, int>> v, v2;
void solve(int cur, int cnt) {
	if (cur == v.size()) {
		ans1 = max(ans1, cnt);
		return;
	}
	int x = v[cur].first;
	int y = v[cur].second;
	if (a[y][x] && !visit[y][x]) {
		for (int i = -N; i < N; i++) {
			int nx = x + i;
			int ny = y + i;
			if (nx >= 0 && ny >= 0 && nx < N && ny < N)
				visit[ny][nx]++;
		}
		for (int i = -N; i < N; i++) {
			int nx = x - i;
			int ny = y + i;
			if (i && nx >= 0 && ny >= 0 && nx < N && ny < N)
				visit[ny][nx]++;
		}
		solve(cur + 1, cnt + 1);
		for (int i = -N; i < N; i++) {
			int nx = x + i;
			int ny = y + i;
			if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
				if (a[ny][nx])
					visit[ny][nx]--;
			}
		}
		for (int i = -N; i < N; i++) {
			int nx = x - i;
			int ny = y + i;
			if (i && nx >= 0 && ny >= 0 && nx < N && ny < N) {
				if (a[ny][nx])
					visit[ny][nx]--;
			}
		}
	}
	solve(cur + 1, cnt);
}
void solve2(int cur, int cnt) {
	if (cur == v2.size()) {
		ans2 = max(ans2, cnt);
		return;
	}
	int x = v2[cur].first;
	int y = v2[cur].second;
	if (a[y][x] && !visit[y][x]) {
		for (int i = -N; i < N; i++) {
			int nx = x + i;
			int ny = y + i;
			if (nx >= 0 && ny >= 0 && nx < N && ny < N)
				visit[ny][nx]++;
		}
		for (int i = -N; i < N; i++) {
			int nx = x - i;
			int ny = y + i;
			if (i && nx >= 0 && ny >= 0 && nx < N && ny < N)
				visit[ny][nx]++;
		}
		solve2(cur + 1, cnt + 1);
		for (int i = -N; i < N; i++) {
			int nx = x + i;
			int ny = y + i;
			if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
				if (a[ny][nx])
					visit[ny][nx]--;
			}
		}
		for (int i = -N; i < N; i++) {
			int nx = x - i;
			int ny = y + i;
			if (i && nx >= 0 && ny >= 0 && nx < N && ny < N) {
				if (a[ny][nx])
					visit[ny][nx]--;
			}
		}
	}
	solve2(cur + 1, cnt);
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
			if (!a[i][j])
				visit[i][j]++;
			else {
				if ((i + j) % 2)
					v.push_back({ j, i });
				else
					v2.push_back({ j, i });
			}
		}
	}
	solve(0, 0);
	solve2(0, 0);
	cout << ans1 + ans2 << "\n";
}