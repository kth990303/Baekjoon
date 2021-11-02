// 200925 #3055 Ż�� Gold V
// ���� �� ���Ľ�Ű��, ���� ���ĵǴ��� tday �迭�� ����
// ���� ����ġ �̵� ����
#include <iostream>
#include <queue>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 51;
const int INF = 1000000007;
int N, M;
char a[MAX][MAX];
int tday[MAX][MAX];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
bool visit[MAX][MAX];
queue<pair<pair<int, int>, int>> waterQ;
struct Place {
	int x, y;
};
Place p[2501];	// �� ��ġ, ���� ��ġ ����
// ���� �����ϴ� bfs
void bfs() {
	while (!waterQ.empty()) {
		int x = waterQ.front().first.first;
		int y = waterQ.front().first.second;
		int day = waterQ.front().second;
		waterQ.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
				if (!visit[ny][nx] && a[ny][nx] == '.') {
					tday[ny][nx] = day + 1;
					visit[ny][nx] = true;
					waterQ.push({ {nx, ny}, day + 1 });
				}
			}
		}
	}
}
// ����ġ �̵� �Լ� bfs2
int bfs2(int x, int y) {
	queue<pair<pair<int, int>, int>> q;
	q.push({ { x, y }, 0 });
	visit[y][x] = true;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int day = q.front().second;
		if (a[y][x]=='D') {
			return day;
		}
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
				if (!visit[ny][nx]) {
					visit[ny][nx] = true;
					if (a[ny][nx] == 'D' || a[ny][nx] == '.') {
						// ���� ���� �ð����� ���� ���
						if (tday[ny][nx] > day) {
							q.push({ {nx, ny}, day + 1 });
						}
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
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			tday[i][j] = INF;
		}
	}
	int k = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'S') {
				p[0] = { j, i };
				tday[i][j] = INF;
			}
			else if(a[i][j]=='D')
				tday[i][j] = INF;
			else if (a[i][j] == '*') {
				// ������ ó�� �� ������ �� �ֺ� 4������ �����Ƿ�
				// ó�� ��ġ�� ���� -1�� ��.
				// �׷��� ���� �� �� ���� ���� 0��° ���� �ǹǷ�
				// ������ �� ���� ������ ������ �� �� ����.
				waterQ.push({ { j, i }, -1 });
				visit[i][j] = true;
				tday[i][j] = 0;
			}
		}
	}
	// ���� ���� ���� ������ waterQ�� �� ������� ����
	bfs();
	memset(visit, false, sizeof(visit));
	int ans = bfs2(p[0].x, p[0].y);
	if (ans >= 0)
		cout << ans << "\n";
	else
		cout << "KAKTUS\n";
}