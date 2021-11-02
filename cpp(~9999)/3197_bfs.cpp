//200830 #3197 ������ ȣ�� Gold I
//���Ͽ����ε� Ǯ���� �ߴµ� �װź��� bfs �ΰ��� �� ����
//�ִܽð�Ǯ�� 3��! (200830 ����, 2���� 1�ð� ��... ����)
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 1501;
char a[MAX][MAX];
bool visit[MAX][MAX];
struct Bird {
	int x, y;
};
Bird bird[2];
int R, C;	// ����, ����
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
queue<pair<int, int>> q, water;
int day = 0;
void showMap() {
	cout << "day: " << day << "\n";
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << a[i][j];
		}
		cout << "\n";
	}
}
void showVisit() {
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cout << visit[i][j];
		}
		cout << "\n";
	}
}
// ������ �����°�?
int bfs(Bird b1, Bird b2) {
	q.push({ b1.x, b1.y });
	while (1) {
		queue<pair<int, int>> nextQ;
		//showMap();
		//showVisit();
		while (!q.empty()) {
			int x = q.front().first;
			int y = q.front().second;
			visit[y][x] = true;
			q.pop();
			if (x == b2.x && y == b2.y)
				return day;
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && ny >= 0 && nx < C && ny < R) {
					if (!visit[ny][nx]) {
						visit[ny][nx] = true;
						if (a[ny][nx] == 'X')
							nextQ.push({ nx, ny });
						else
							q.push({ nx, ny });
					}
				}
			}
		}
		//showVisit();
		// ���� ���̱�
		int waterNum = water.size();
		while (waterNum--) {
			int x = water.front().first;
			int y = water.front().second;
			water.pop();
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx >= 0 && ny >= 0 && nx < C && ny < R) {
					if (a[ny][nx] == 'X') {
						a[ny][nx] = '.';
						water.push({ nx, ny });
					}
				}
			}
		}
		day++;
		q = nextQ;
	}	
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> R >> C;
	int k = 0;
	for (int i = 0; i < R; i++) {
		cin >> a[i];
		for (int j = 0; j < C; j++) {
			if (a[i][j] == 'L') {
				bird[k].x = j;
				bird[k].y = i;
				a[i][j] = '.';
				k++;
			}
			if (a[i][j] == '.')
				water.push({ j, i });
		}
	}
	cout << bfs(bird[0], bird[1]);
}