// 200821 DFS+DP Gold III
// ������ dfs + dp�̳�, �ð��ʰ� ����
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
	// �̰� �߰� ���ϸ� �ð��ʰ� => dp_�޸������̼�
	// �̰� �߰� ���ϸ� O(N^2)
	// �̰� �߰��ϸ� O(N)
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
	// dp ������ O(N^4)=> 500^4=>62.5��=>62��... (�Ƹ�?)
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (!finished[i][j])
				K = max(K, dfs(j, i));
		}
	}
	cout << K;
}