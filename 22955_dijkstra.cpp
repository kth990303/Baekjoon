// 210830 #22955 고양이 도도의 탈출기 Gold III
// dijkstra O(NMlg(NM))
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
const int MAX = 1001;
const int INF = 0x3f3f3f3f;
int N, M, ans, Sx, Sy, d[MAX][MAX];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
char a[MAX][MAX];
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			a[i][j] = s[j];
			if (a[i][j] == 'C')
				Sx = j, Sy = i;
		}
	}
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0, {Sx, Sy} });
	memset(d, INF, sizeof(d));
	d[Sy][Sx] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		if (a[y][x] == 'E') {
			cout << cost << "\n";
			return 0;
		}
		if (d[y][x] < cost)
			continue;
		if (a[y][x] == 'L') {
			int nx = x + dx[0];
			int ny = y + dy[0];
			int nCost = cost + 5;				
			if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
				if (a[ny][nx] != 'D' && nCost < d[ny][nx]) {
					d[ny][nx] = nCost;
					pq.push({ nCost, {nx, ny} });
				}
			}
		}
		// if a[y][x]=='X', then can't use ladder
		if (a[y][x]!='X' && y + 1 < N && a[y + 1][x] == 'L') {
			int nx = x + dx[1];
			int ny = y + dy[1];
			int nCost = cost + 5;
			if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
				if (a[ny][nx] != 'D' && nCost < d[ny][nx]) {
					d[ny][nx] = nCost;
					pq.push({ nCost, {nx, ny} });
				}
			}
		}
		if (a[y][x] == 'X') {
			int nx = x;
			int ny;
			for (ny = y + 1; ny < N; ny++) {
				if (a[ny][nx] != 'X')
					break;
			}
			int nCost = cost + 10;
			if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
				if (a[ny][nx] != 'D' && nCost < d[ny][nx]) {
					d[ny][nx] = nCost;
					pq.push({ nCost, {nx, ny} });
				}
			}
		}
		if (a[y][x] != 'X') {
			for (int i = 2; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				int nCost = cost + 1;
				if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
					if (a[ny][nx] != 'D' && nCost < d[ny][nx]) {
						d[ny][nx] = nCost;
						pq.push({ nCost, {nx, ny} });
					}
				}
			}
		}
	}
	cout << "dodo sad\n";
}