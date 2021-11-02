// 201227 #9328 ���� Gold I
// ����� ���� �߿��� ���� ���� BFS
// ���踦 ã�� ���, �� ��ġ�� ť�� ����ְ� �ϸ�,
// �ٽ� ó������ �����ϴ� ��캸�� 100�� �� ����. (440ms -> 4ms)
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
const int MAX = 103;
using namespace std;
int N, M, ans;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
char a[MAX][MAX];
bool key[26];
bool visit[MAX][MAX];
void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({x, y});
	visit[y][x] = true;
	vector<pair<int, int>> door[26];
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
				if (!visit[ny][nx]) {
					if (a[ny][nx] == '$') {
						ans++;
						a[ny][nx] = '.';
						visit[ny][nx] = true;
						q.push({ nx, ny });
					}
					if (a[ny][nx] >= 'A' && a[ny][nx] <= 'Z') {
						if (!key[a[ny][nx] - 'A']) {
							door[a[ny][nx] - 'A'].push_back({ nx, ny });
						}
						else {
							visit[ny][nx] = true;
							a[ny][nx] = '.';
							q.push({ nx, ny });
						}
					}
					else if (a[ny][nx] >= 'a' && a[ny][nx] <= 'z') {
						key[a[ny][nx] - 'a'] = true;
						for (auto j : door[a[ny][nx] - 'a'])
							q.push(j);
						visit[ny][nx] = true;
						q.push({ nx, ny });
					}
					else if (a[ny][nx] == '.') {
						visit[ny][nx] = true;
						q.push({ nx, ny });
					}
				}
			}
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		ans = 0;
		memset(visit, false, sizeof(visit));
		fill(key, key + 26, false);

		cin >> N >> M;
		// �׵θ��� ������༭ ������ �� �ְ�
		for (int i = 0; i <= M; i++)
			a[0][i] = '.';
		for (int i = 1; i <= N; i++) {
			a[i][0] = '.';
			for (int j = 1; j <= M; j++)
				cin >> a[i][j];
			a[i][M + 1] = '.';
		}
		for (int i = 0; i <= M+1; i++)
			a[N + 1][i] = '.';

		string k;
		cin >> k;
		for (int i = 0; i < k.length(); i++) {
			if (k == "0")
				break;
			key[k[i] - 'a'] = true;	// Ű�� bool�����ε� ���
		}
		// �׵θ� ������ ����, ���� ���̰� �����.
		N += 2; M += 2;
		bfs(0, 0);
		cout << ans << "\n";
	}
}