// 201226 #2583 영역 구하기 Silver I
// DFS 풀이, 시간복잡도: O(NM)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 101;
int N, M, K, cnt, a[MAX][MAX];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
bool visit[MAX][MAX];
int dfs(int x, int y) {
	visit[y][x] = true;
	// 자기 자신
	int ans = 1;
	// DFS로 4방면 탐색, DFS의 시간복잡도: O(V+E)
	// O(4NM) -> O(NM)
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
			if (!visit[ny][nx] && !a[ny][nx]) {
				ans += dfs(nx, ny);	// dfs(재귀) 성질 이용
			}
		}
	}
	return ans;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;	// 세로 가로 순서
	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		// 점 단위로 하지 않고, 모눈 1칸 단위로 바꿈.
		for (int i = y1 + 1; i <= y2; i++) {
			for (int j = x1; j < x2; j++) {
				// x좌표는 오른쪽 위 좌표를 포함하지 않고 색칠.
				// y좌표는 왼쪽 아래 좌표를 포함하지 않고 색칠.
				a[N - i][j] = 1;
				// 이미 색칠된 곳은 볼 필요 없음.
				visit[N - i][j] = true;
			}
		}
	}
	vector<int> ans;	// 색칠된 칸 넓이 담는 배열
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			// 방문하지 않은 곳인데 탐색해야 되는 곳이면
			if (!visit[i][j] && !a[i][j]) {
				// 컴포넌트 수 증가
				cnt++;
				// 탐색 시작
				ans.push_back(dfs(j, i));
			}
		}
	}
	sort(ans.begin(), ans.end());
	cout << cnt << "\n";
	for (auto i : ans) {
		cout << i << " ";
	}
}