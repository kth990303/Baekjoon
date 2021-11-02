// 200825 #4485 dijkstra_�������迭 Gold IV
// ó������ ���ͽ�Ʈ�� ��� �������� �������� ��������
// ���� Ǯ���
#include <iostream>
#include <queue>
using namespace std;
typedef pair<int, pair<int, int>> ppii;
const int INF = 1000000007;
int N, ans;
int a[125][125];
int money[125][125];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int bfs(int x, int y) {
	// cost�� �켱������ �ϱ� ���� �߹���...
	priority_queue<ppii, vector<ppii>, greater<ppii>> q;
	q.push({ a[y][x], {x,y} });
	// ������ �������� dijkstra
	while (!q.empty()) {
		int x = q.top().second.first;
		int y = q.top().second.second;
		int cost = q.top().first;
		q.pop();
		if (money[y][x] < cost)
			continue;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			int nCost = cost + a[ny][nx];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
				if (nCost < money[ny][nx]) {
					money[ny][nx] = nCost;
					q.push({ nCost, {nx, ny} });
				}
			}
		}
	}
	return money[N - 1][N - 1];
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int cnt = 0;
	while (1) {
		++cnt;
		cin >> N;
		if (!N)
			break;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> a[i][j];
				money[i][j] = INF;
			}
		}
		ans = bfs(0, 0);
		cout << "Problem " << cnt << ": " << ans << "\n";
	}
}