// 201226 #2583 영역 구하기 Silver I
// BFS 풀이, 시간복잡도: O(NM)
// dfs풀이보다 메모리가 적게 나가며, 시간 또한 빠름. (재귀 이용 x)
// bfs를 이용한다는 점 외엔 dfs와 동일하다.
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 101;
int N, M, K, cnt, a[MAX][MAX];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
bool visit[MAX][MAX];
int bfs(int x, int y, int ans) {
	queue<pair<int, int>> q;
	visit[y][x] = true;	// 큐에서 팝하기 전에 visit처리를 해줘야 함.
	q.push({ x, y });
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
				if (!visit[ny][nx] && !a[ny][nx]) {
					// 조건에 맞는 것들만 탐색시킴.
					q.push({ nx, ny });
					visit[ny][nx] = true;
					ans++;
				}
			}
		}
	}
	return ans;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		for (int i = y1 + 1; i <= y2; i++) {
			for (int j = x1; j < x2; j++) {
				a[N - i][j] = 1;
				visit[N - i][j] = true;
			}
		}
	}
	vector<int> ans;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visit[i][j] && !a[i][j]) {
				cnt++;
				ans.push_back(bfs(j, i, 1));
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << cnt << "\n";
	for (auto i : ans) {
		cout << i << " ";
	}
}