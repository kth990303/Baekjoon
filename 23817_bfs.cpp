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
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
const int MAX = 1011;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e16;
const int MOD = 1e9 + 7;
int N, M, K, S, ans = INF;
string s;
int b[MAX][MAX], cost[23][23];
char a[MAX][MAX];
bool vis[MAX][MAX], vis2[MAX];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
void bfs(int x, int y, int start) {
	queue<pii> q;
	q.push({ 0, {x,y} });
	vis[y][x] = true;
	while (!q.empty()) {
		int t = q.front().first;
		int x = q.front().second.first;
		int y = q.front().second.second;
		q.pop();
		if (b[y][x]) {
			cost[start][b[y][x]] = t;
			cost[b[y][x]][start] = t;
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx >= 0 && ny >= 0 && nx < M && ny < N) {
				if (!vis[ny][nx] && a[ny][nx] != 'X') {
					vis[ny][nx] = true;
					q.push({ t + 1, {nx, ny} });
				}
			}
		}
	}
}
void solve(int cur, int dis, int cnt) {
	if (cnt == 5) {
		ans = min(ans, dis);
		return;
	}
	for (int i = 1; i <= K; i++) {
		if (!vis2[i] && cost[cur][i] < INF) {
			vis2[i] = true;
			solve(i, dis + cost[cur][i], cnt + 1);
			vis2[i] = false;
		}
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> s;
		for (int j = 0; j < M; j++) {
			a[i][j] = s[j];
			if (a[i][j] == 'S') {
				b[i][j] = ++K;
				S = K;
			}
			if (a[i][j] == 'K') {
				b[i][j] = ++K;
			}
		}
	}
	if (K < 5) {
		cout << -1;
		return 0;
	}
	memset(cost, INF, sizeof(cost));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (b[i][j]) {
				memset(vis, false, sizeof(vis));
				bfs(j, i, b[i][j]);
			}
		}
	}
	vis2[S] = true;
	solve(S, 0, 0);
	if (ans >= INF)
		cout << -1;
	else
		cout << ans;
}