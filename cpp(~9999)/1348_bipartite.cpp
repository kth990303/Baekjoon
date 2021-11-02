// 210621 #1348 ÁÖÂ÷Àå Platinum II
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 51;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int R, C, d[101], dis[101][101], visit[MAX][MAX];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
vector<pi> place, car;
vector<int> v[101];
char a[MAX][MAX];
bool used[101];
void bfs(int x, int y, int idx) {
	queue<pi> q;
	q.push({ x, y });
	visit[y][x] = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < C && ny < R) {
				if (visit[ny][nx] == -1 && a[ny][nx] != 'X') {
					visit[ny][nx] = visit[y][x] + 1;
					q.push({ nx, ny });
				}
			}
		}
	}
	// All place memoization => visit type int
	for (int i = 0; i < place.size(); i++) {
		if (visit[place[i].second][place[i].first] == -1)
			dis[idx][i] = INF;
		else {
			v[idx].push_back(i);
			dis[idx][i] = visit[place[i].second][place[i].first];
		}
	}
}
bool dfs(int cur, int time) {
	for (auto i : v[cur]) {
		if (used[i] || dis[cur][i] > time)
			continue;
		used[i] = true;
		if (d[i] == -1 || dfs(d[i], time)) {
			d[i] = cur;
			return true;
		}
	}
	return false;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < C; j++) {
			a[i][j] = s[j];
			if (s[j] == 'C')
				car.push_back({ j, i });
			else if (s[j] == 'P')
				place.push_back({ j, i });
		}
	}
	if (car.size() > place.size()) {
		cout << -1 << "\n";
		return 0;
	}
	// O(100*100*100)
	for (int i = 0; i < car.size(); i++) {
		memset(visit, -1, sizeof(visit));
		bfs(car[i].first, car[i].second, i);
	}
	int ans = -1, s = 0, e = MAX * MAX;
	// binary_Search && bipartite matching O(log(2500)*100*100))
	while (s <= e) {
		int mid = (s + e) / 2, ret = 0;
		fill(d, d + 101, -1);
		for (int i = 0; i < car.size(); i++) {
			fill(used, used + 101, false);
			if (dfs(i, mid))
				ret++;
		}
		if (ret == car.size()) {
			ans = mid;
			e = mid - 1;
		}
		else
			s = mid + 1;
	}
	cout << ans << "\n";
}