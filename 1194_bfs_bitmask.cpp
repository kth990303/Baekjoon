// 200824 #1194 ���� ��������, ����. Gold I
// ��ģ����.... ���̵� ���ƾ�....
// bfs(�ִܰ��)+bitmask+����
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
char a[51][51];
int visit[51][51][1<<7];	// 111111
// ���迡 ���� �湮������ ���¸� �ٸ��� �ؾߵ�!
// �׷��� ���� ���, ���� ���� �� �ٽ� �ǵ��ư��� ����
// boolean ������ ���� üũ -> bitmask
// �� �湮���ΰ� �� ������ �ٽ�
int ans;
int bfs(int x, int y, int k) {
	queue<pair<pair<int, int>, int>> q;
	q.push({ { x,y }, k });
	visit[y][x][k] = 1;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int k = q.front().second;
		q.pop();
		if (a[y][x] == '1') {
			return visit[y][x][k] - 1;
		}
		// bfs ����
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
				if (!visit[ny][nx][k]) {
					if (a[ny][nx] == '#')
						continue;
					if (a[ny][nx] >= 'a' && a[ny][nx] <= 'f') {
						int nk = k | (1 << (a[ny][nx] - 'a'));
						visit[ny][nx][nk] = visit[y][x][k] + 1;
						//a[ny][nx] = '.';
						//�� �ּ��κ��� ������ �Ƹ���ϳ�...
						//���踦 ���� ���� nk�� �ؾߵǴϱ�!
						q.push({ { nx, ny }, nk });
					}
					else if (a[ny][nx] >= 'A' && a[ny][nx] <= 'F') {
						int nk = k & (1 << (a[ny][nx] - 'A'));
						// ��Ʈ����ũ �ʺ��� nk==1���� �ϴٰ� ���к�
						// 100000, 010000 ���� ��찡 ���ݾ�...
						if (nk!=0) {
							visit[ny][nx][k] = visit[y][x][k] + 1;
							q.push({ { nx, ny }, k });
						}
						else
							continue;
					}
					else {
						visit[ny][nx][k] = visit[y][x][k] + 1;
						q.push({ { nx, ny }, k });
					}
				}
			}
		}
	}
	return -1;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++)
		cin >> a[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (a[i][j] == '0')
				ans = bfs(j, i, 0);
		}
	}
	if (ans == 0)
		cout << -1;
	else
		cout << ans;
}