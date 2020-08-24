// 200824 �Ｚ A�� ���⹮��
// #17472 �ٸ������ 2 MST, BFS, Gold III
// �Ｚ������� ���� ����... Gold II�� �ž� �� �� ������,,,
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int a[101][101];	// map
int p[101][101];	// ���� ������ �ƴ���
bool visit[101][101];	// bfs�� �� �湮 ����
int N, M;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int cnt = 0;	// ���� ��ȣ
queue<pair<int, int>> q;
vector<pair<int, int>> v[7];	// ���� ������ ��ǥ ����
vector<pair<int, pair<int, int>>> d;	// �� ���� �Ÿ� ����
int parent[7];	// ���鰣 ���������� (mst)
int ans;

int find(int a) {
	if (a == parent[a])
		return a;
	return parent[a] = find(parent[a]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return false;
	parent[b] = a;
	return true;
}

void bfs(int x, int y) {
	q.push({ x,y });
	visit[y][x] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		p[y][x] = cnt;
		v[cnt].push_back({ y,x });
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
				if (!visit[ny][nx] && a[ny][nx] == 1) {
					q.push({ nx,ny });
					visit[ny][nx] = true;
					p[ny][nx] = cnt;
				}
			}
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a[i][j];
		}
	}
	// ���鰣 ��ȣ �ο��ϱ� ���� �׷���Ž��
	// bfs��
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visit[i][j] && a[i][j]==1) {
				++cnt;
				bfs(j, i);
			}
		}
	}

	// ���鰣 �Ÿ� ���ϱ� (���������� ���� ���� �κ�)
	for (int i = 1; i <= cnt; i++) {
		for (int j = i + 1; j <= cnt; j++) {
			int distance = 110;	// INF
			for (auto p1 : v[i]) {
				for (auto q1 : v[j]) {
					if (p1.first == q1.first) {
						if (abs(p1.second - q1.second) > 2) {
							// �߰��� �ٴٰ� ������ flag=false;
							bool flag = true;
							for (int start = min(p1.second, q1.second) + 1; start < max(p1.second, q1.second); start++) {
								if (a[p1.first][start] != 0) {
									flag = false;
									break;
								}
							}
							// �ùٸ� �ٸ��̰� ª�� ��쿡��
							if (flag == true)
								distance = min(abs(p1.second - q1.second) - 1, distance);
						}
					}
					if (p1.second == q1.second) {
						if (abs(p1.first - q1.first) > 2){
							bool flag = true;
							for (int start = min(p1.first, q1.first) + 1; start < max(p1.first, q1.first); start++) {
								if (a[start][p1.second] != 0) {
									flag = false;
									break;
								}
							}
							if(flag==true)
								distance = min(abs(p1.first - q1.first) - 1, distance);
						}
							
					}
				}
			}
			// kruskal algorithm ����ϱ� ���� ����
			if(distance<110)
				d.push_back({ distance, {i, j} });
		}
	}
	// ���鰣 �ٸ� ���� (MST)
	for (int i = 1; i <= cnt; i++) {
		parent[i] = i;
	}
	sort(d.begin(),d.end());
	for (int i = 0; i < d.size(); i++) {
		int island1 = d[i].second.first;
		int island2 = d[i].second.second;
		int dis = d[i].first;
		if (merge(island1, island2)) {
			ans += dis;
		}
	}
	// �Ұ����� ���� flag2=false (union-find)
	bool flag2 = true;
	for (int i = 1; i <= cnt; i++) {
		if (find(1) != find(i)) {
			flag2 = false;
		}
	}
	if (!flag2) {
		cout << -1;
	}
	else
		cout << ans;
}