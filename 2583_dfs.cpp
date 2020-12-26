// 201226 #2583 ���� ���ϱ� Silver I
// DFS Ǯ��, �ð����⵵: O(NM)
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
	// �ڱ� �ڽ�
	int ans = 1;
	// DFS�� 4��� Ž��, DFS�� �ð����⵵: O(V+E)
	// O(4NM) -> O(NM)
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
			if (!visit[ny][nx] && !a[ny][nx]) {
				ans += dfs(nx, ny);	// dfs(���) ���� �̿�
			}
		}
	}
	return ans;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;	// ���� ���� ����
	for (int i = 0; i < K; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		// �� ������ ���� �ʰ�, �� 1ĭ ������ �ٲ�.
		for (int i = y1 + 1; i <= y2; i++) {
			for (int j = x1; j < x2; j++) {
				// x��ǥ�� ������ �� ��ǥ�� �������� �ʰ� ��ĥ.
				// y��ǥ�� ���� �Ʒ� ��ǥ�� �������� �ʰ� ��ĥ.
				a[N - i][j] = 1;
				// �̹� ��ĥ�� ���� �� �ʿ� ����.
				visit[N - i][j] = true;
			}
		}
	}
	vector<int> ans;	// ��ĥ�� ĭ ���� ��� �迭
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			// �湮���� ���� ���ε� Ž���ؾ� �Ǵ� ���̸�
			if (!visit[i][j] && !a[i][j]) {
				// ������Ʈ �� ����
				cnt++;
				// Ž�� ����
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