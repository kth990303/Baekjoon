// 200824 삼성 A형 기출문제
// #17472 다리만들기 2 MST, BFS, Gold III
// 삼성문제답게 빡센 구현... Gold II는 돼야 할 거 같은데,,,
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int a[101][101];	// map
int p[101][101];	// 같은 섬인지 아닌지
bool visit[101][101];	// bfs할 때 방문 여부
int N, M;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int cnt = 0;	// 섬의 번호
queue<pair<int, int>> q;
vector<pair<int, int>> v[7];	// 섬의 개수의 좌표 저장
vector<pair<int, pair<int, int>>> d;	// 섬 간의 거리 저장
int parent[7];	// 섬들간 합쳐지는지 (mst)
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
	// 섬들간 번호 부여하기 위한 그래프탐색
	// bfs로
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visit[i][j] && a[i][j]==1) {
				++cnt;
				bfs(j, i);
			}
		}
	}

	// 섬들간 거리 구하기 (개인적으로 제일 빡센 부분)
	for (int i = 1; i <= cnt; i++) {
		for (int j = i + 1; j <= cnt; j++) {
			int distance = 110;	// INF
			for (auto p1 : v[i]) {
				for (auto q1 : v[j]) {
					if (p1.first == q1.first) {
						if (abs(p1.second - q1.second) > 2) {
							// 중간에 바다가 있으면 flag=false;
							bool flag = true;
							for (int start = min(p1.second, q1.second) + 1; start < max(p1.second, q1.second); start++) {
								if (a[p1.first][start] != 0) {
									flag = false;
									break;
								}
							}
							// 올바른 다리이고 짧은 경우에만
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
			// kruskal algorithm 사용하기 위한 형태
			if(distance<110)
				d.push_back({ distance, {i, j} });
		}
	}
	// 섬들간 다리 연결 (MST)
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
	// 불가능한 경우는 flag2=false (union-find)
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