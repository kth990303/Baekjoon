// 200821 DFS+DP Gold III
// 무난한 dfs + dp이나, 시간초과 주의
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int a[500][500];
int N, K;
int finished[500][500];
int dfs(int x, int y) {
	// 이거 추가 안하면 시간초과 => dp_메모이제이션
	// 이거 추가 안하면 O(N^2)
	// 이거 추가하면 O(N)
	if (finished[y][x])
		return finished[y][x];
	finished[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
			if (a[ny][nx] > a[y][x]) {
				finished[y][x] = max(finished[y][x], dfs(nx, ny)+1);
			}
		}
	}
	return finished[y][x];
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
	// dp 없으면 O(N^4)=> 500^4=>62.5억=>62초... (아마?)
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!finished[i][j])
				K = max(K, dfs(j, i));
		}
	}
	cout << K;
}