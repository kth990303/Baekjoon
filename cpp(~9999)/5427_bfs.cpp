// 210214 #5427 �� Gold IV
// BFS + �Ｚ sw�����׽�Ʈ ��õ���� + ����
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
#include <cstring>
using namespace std;
const int MAX = 1001;
// ���� ��ǥ
struct Point {
	int x, y;
};
Point me;
// �� ��ǥ ����
vector<Point> fire;
int H, W, ans, ntime = -1;
bool flag = true;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
char a[MAX][MAX];
bool visit[MAX][MAX];
queue<pair<int, int>> q2;
// ���� �̵�
void bfs2() {
	int num = fire.size();
	// ó���� ���� num���� �����ϸ�,
	// ���� queue�� ���� �ʰ� �̵��� �ϸ� ��
	for (int i = 0; i < num; i++) {
		int x = fire[i].x;
		int y = fire[i].y;
		for (int j = 0; j < 4; j++) {
			int nx = x + dx[j];
			int ny = y + dy[j];
			if (nx >= 0 && ny >= 0 && nx < W && ny < H) {
				// ���� ��� �׳� visitó�� ���ѹ���
				// �׸��� .�� ��츸 ���� �̵�������
				// ó���� if(a[ny][nx]!='#')���θ� �ߴµ� MLE...
				if (!visit[ny][nx] && a[ny][nx] == '.') {
					a[ny][nx] = '*';
					visit[ny][nx] = true;
					fire.push_back({ nx, ny });
				}
			}
		}
	}
	// ���� ���� ������ �þ.
	num = fire.size();
}
// Ż���ϱ� ���� �� �ڽ��� bfs
void bfs(int x, int y) {
	queue<pair<pair<int, int>, int>> q;
	q.push({ { x, y }, 0 });
	visit[y][x] = true;
	while (!q.empty()) {
		int x = q.front().first.first;
		int y = q.front().first.second;
		int time = q.front().second;
		q.pop();
		// �̵� �ð��� �����ϱ� ����������
		// �� �̵���Ű�� Ž�� ����
		if (ntime < time) {
			ntime = time;
			bfs2();
		}
		/*
		cout << "\n";
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cout << a[i][j];
			}
			cout << "\n";
		}*/
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < W && ny < H) {
				if (!visit[ny][nx]) {
					if (a[ny][nx] == '.') {
						visit[ny][nx] = true;
						q.push({ {nx, ny}, time + 1 });
					}
				}
			}
			// �����ڸ��� �ִ� ���
			// Ż���ϸ� �ǹǷ� time+1�� ��������
			else {
				flag = true;
				ans = time + 1;
				return;
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
		ntime = -1;
		flag = false;
		ans = 0;
		memset(a, false, sizeof(a));
		memset(visit, false, sizeof(visit));
		fire.clear();
		cin >> W >> H;
		for (int i = 0; i < H; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < W; j++) {
				a[i][j] = s[j];
				if (a[i][j] == '@') {
					me.y = i;
					me.x = j;
				}
				// ���� ��� ������ �̵� ���ϹǷ� visitó�� ��
				else if (a[i][j] == '#') {
					visit[i][j] = true;
				}
				// ���� ��� ������ �̵����ϹǷ� visitó�� ��
				else if (a[i][j] == '*') {
					visit[i][j] = true;
					fire.push_back({ j, i });
				}
			}
		}
		bfs(me.x, me.y);
		if (flag)
			cout << ans << "\n";
		else
			cout << "IMPOSSIBLE" << "\n";
	}
}