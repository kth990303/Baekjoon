// 220409 #13459 ±∏ΩΩ≈ª√‚ Gold II
// impl, bfs, simulation
// Algorithm_company_study assignment5
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
const int MAX = 11;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e16;
const int MOD = 1e9 + 7;
int N, M, OX, OY, flag;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
struct Marble {
	int x, y, flag;
};
Marble marble[2];
char a[MAX][MAX];
bool vis[MAX][MAX][MAX][MAX];
Marble move(int dir, Marble tmp, int kind, int other_x, int other_y) {
	Marble m = tmp;
	int flag = 0;
	while (a[m.y + dy[dir]][m.x + dx[dir]] != '#') {
		if (a[m.y + dy[dir]][m.x + dx[dir]] == 'O') {
			m.y = OY, m.x = OX;
			m.flag += (1 << kind);
			break;
		}
		if (m.y + dy[dir] == other_y && m.x + dx[dir] == other_x)break;
		m.y += dy[dir], m.x += dx[dir];
	}
	return m;
}
int solve(int cur) {
	queue<pair<int, pair<Marble, Marble>>> q;
	q.push({ cur,{marble[0],marble[1]} });
	vis[marble[0].y][marble[0].x][marble[1].y][marble[1].x] = true;
	while (!q.empty()) {
		int cnt = q.front().first;
		Marble red = q.front().second.first;
		Marble blue = q.front().second.second;
		q.pop();
		if (cnt > 10)continue;
		if (red.flag + blue.flag == 1) return 1;
		for (int i = 0; i < 4; i++) {
			Marble nxt_red, nxt_blue;
			if ((!i && blue.x == red.x && blue.y < red.y)
				|| (i == 1 && blue.x == red.x && blue.y > red.y)
				|| (i == 2 && blue.x < red.x && blue.y == red.y)
				|| (i == 3 && blue.x > red.x && blue.y == red.y)) {
				nxt_blue = move(i, blue, 1, red.x, red.y);
				nxt_red = move(i, red, 0, nxt_blue.x, nxt_blue.y);
			}
			else {
				nxt_red = move(i, red, 0, blue.x, blue.y);
				nxt_blue = move(i, blue, 1, nxt_red.x, nxt_red.y);
			}
			if (vis[nxt_red.y][nxt_red.x][nxt_blue.y][nxt_blue.x])continue;
			if (nxt_red.flag + nxt_blue.flag > 1)continue;
			vis[nxt_red.y][nxt_red.x][nxt_blue.y][nxt_blue.x] = true;
			q.push({ cnt + 1,{nxt_red,nxt_blue} });
		}
	}
	return 0;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			a[i][j] = s[j];
			if (a[i][j] == 'R') {
				marble[0].x = j, marble[0].y = i;
			}
			else if (a[i][j] == 'B') {
				marble[1].x = j, marble[1].y = i;
			}
			else if (a[i][j] == 'O') {
				OX = j, OY = i;
			}
		}
	}
	cout << solve(0);
}