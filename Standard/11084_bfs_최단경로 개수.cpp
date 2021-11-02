// 200903 #11084 ����Ʈ�� ��Ž Gold II
// �ִܰ���� "����", ����Ʈ�� �������� �̵��ݰ�
#include <iostream>
#include <queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pii;
const int MAX = 401;
const ll MOD = 1000000009;
int dx[8] = { -2,-1,1,2,-2,-1,1,2 };
int dy[8] = { -1,-2,-2,-1,1,2,2,1 };
bool visit[MAX][MAX];
pii d[MAX][MAX];	// first:�Ÿ� , second:���� ��
int r, c;
void bfs(int x, int y) {
	queue<pii> q;
	q.push({ x,y });
	visit[y][x] = true;
	d[y][x].second = 1;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < c && ny < r) {
				// �湮���� ���� ���̸�
				if (!visit[ny][nx]) {
					// ����� ���� �翬�� �����ϰ�
					d[ny][nx].second += d[y][x].second;
					d[ny][nx].second %= MOD;
					// q�� �����ؼ� ���⼭���� ����
					q.push({ nx, ny });
					visit[ny][nx] = true;
					d[ny][nx].first = d[y][x].first + 1;
				}
				// �湮�ߴµ� �̵� ������ ����� ���̸�
				// ���� �������� �ٸ� ��� �� ����̹Ƿ�
				// ���±����� ����� ����� ���� ������.
				else if (d[ny][nx].first == d[y][x].first + 1) {
					d[ny][nx].second += d[y][x].second;
					d[ny][nx].second %= MOD;
				}
			}
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> r >> c;
	bfs(0, 0);
	if (!d[r-1][c-1].second)
		cout << "None\n";
	else {
		cout << d[r-1][c-1].first << " " << d[r-1][c-1].second << "\n";
	}
}