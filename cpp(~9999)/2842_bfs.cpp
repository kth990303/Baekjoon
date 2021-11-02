// 210403 #2842 집배원 한상덕 Platinum V
// bfs + two_pointers
// O(N^4)
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <queue>
#include <vector>
#define all(v) v.begin(), v.end()
using namespace std;
struct Point {
	int x, y;
};
Point p;
const int MAX = 51;
const int INF = 1e9 + 7;
int N, h[MAX][MAX], cnt, s, e, num, ans = INF;
int dx[8] = { 0,0,-1,1,-1,1,-1,1 };
int dy[8] = { -1,1,0,0,-1,-1,1,1 };
char a[MAX][MAX];
bool visit[MAX][MAX];
vector<int> v;
// O(N^2)
void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x, y });
	visit[y][x] = true;
	// if you don't check this condition
	// 55% WA
	if (v[s] > h[y][x] || v[e] < h[y][x])
		return;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 8; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < N && ny < N) {
				if (!visit[ny][nx] && h[ny][nx] >= v[s] 
					&& h[ny][nx] <= v[e]) {
					if (a[ny][nx] == 'K')
						num++;
					visit[ny][nx] = true;
					q.push({ nx, ny });
				}
			}
		}
	}
	
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			a[i][j] = s[j];
			if (a[i][j] == 'K')
				cnt++;
			else if (a[i][j] == 'P')
				p.y = i, p.x = j;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> h[i][j];
			v.push_back(h[i][j]);
		}
	}
	// coordination compression
	sort(all(v));
	v.erase(unique(all(v)), v.end());
	// two_pointers (O(N*N))
	while (s <= e) {
		if (e == v.size())
			break;
		memset(visit, false, sizeof(visit));
		num = 0;
		bfs(p.x, p.y);
		if (num < cnt) {
			e++;
		}
		else {
			ans = min(ans, v[e] - v[s]);
			s++;
		}
	}
	cout << ans << "\n";
}