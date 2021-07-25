// 210725 #22237 °¡Èñ¿Í °ÅºÏÀÌ ÀÎÇü Platinum V
// bfs + trace
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 3001;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
struct Point {
	int x, y;
};
Point p[21];
struct Box {
	int x1=INF, x2, y1=INF, y2;
};
Box box;
int R, C, cnt = 1, res, Ex = -1, Ey = -1;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
char a[MAX][MAX], b[MAX][MAX];
int visit[MAX][MAX];
vector<char> ans;
void init(int x, int y) {
	b[y][x] = 'H';
	for (int i = 1; i < cnt; i++) {
		int nx = x + p[i].x;
		int ny = y + p[i].y;
		b[ny][nx] = '#';
	}
}
bool check(int x, int y) {
	if (y - p[0].y > box.y1 - 1000 || p[0].y-y > R + 1000 - box.y2 - 1
		|| x - p[0].x > box.x1 - 1000|| p[0].x - x > C + 1000 - box.x2 - 1)
		return false;
	for (int i = 1; i < cnt; i++) {
		int nx = x + p[i].x;
		int ny = y + p[i].y;
		if (a[ny][nx] == 'T')
			return false;
	}
	return true;
}
void bfs(int x, int y) {
	queue<pi> q;
	q.push({x, y});
	visit[y][x] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		init(x, y);
		res = max(res, visit[y][x]);
		if (a[y][x] == 'T') {
			Ex = x, Ey = y;
			return;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (visit[ny][nx] == -1 && check(nx, ny)) {
				visit[ny][nx] = visit[y][x] + 1;
				q.push({ nx, ny });
			}
		}
	}
	if (Ex == -1 && Ey == -1) {
		cout << -1 << "\n";
		return;
	}
}
void trace(int x, int y, int n) {
	if (!n) {
		for (int i = ans.size() - 1; i >= 0; i--) {
			cout << ans[i];
		}
		exit(0);
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (visit[ny][nx] == visit[y][x] - 1) {
			if (i == 0)
				ans.push_back('U');
			else if (i == 1)
				ans.push_back('D');
			else if (i == 2)
				ans.push_back('L');
			else
				ans.push_back('R');
			trace(nx, ny, n - 1);
		}
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> R >> C;
	memset(visit, -1, sizeof(visit));
	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < C; j++) {
			a[i+1000][j + 1000] = s[j];
			if (a[i + 1000][j + 1000] == 'H') {
				p[0].x = j + 1000, p[0].y = i + 1000;
			}
		}
	}
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (a[i + 1000][j + 1000] == '#') {
				p[cnt].x = j + 1000 - p[0].x;
				p[cnt].y = i + 1000 - p[0].y;
				cnt++;
			}
			if (a[i + 1000][j + 1000] == 'T') {
				box.x1 = min(box.x1, j + 1000);
				box.x2 = max(box.x2, j + 1000);
				box.y1 = min(box.y1, i + 1000);
				box.y2 = max(box.y2, i + 1000);
			}
		}
	}
	bfs(p[0].x, p[0].y);
	if (Ex != -1 && Ey != -1) {
		trace(Ex, Ey, res);
	}
}