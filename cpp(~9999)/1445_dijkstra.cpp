// 211206 #1445 일요일아침의데이트 Gold II
// dijkstra
// trash: cost MAX*MAX
// beside trash: cost 1
// not beside trash: cost 0 -> visit array
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
typedef pair<ll, pl> pll;
const int MAX = 52;
const int INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N, M, sx, sy, d[MAX][MAX], a[MAX][MAX];
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
char aa[MAX][MAX];
bool vis[MAX][MAX];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			aa[i][j] = s[j];
			if (aa[i][j] == 'S') {
				sx = j, sy = i;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (aa[i][j] == 'g') {
				a[i][j] = MAX * MAX;
				for (int k = 0; k < 4; k++) {
					int nx = j + dx[k];
					int ny = i + dy[k];
					if (nx >= 0 && ny >= 0 && nx < M && ny < N && aa[ny][nx] == '.') {
						a[ny][nx] = 1;
					}
				}
			}
		}
	}
	/*for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << (a[i][j] > 1 ? 2 : a[i][j]);
		}
		cout << "\n";
	}*/
	priority_queue<pii, vector<pii>, greater<pii>> pq;
	pq.push({ 0, {sx, sy} });
	memset(d, INF, sizeof(d));
	d[sy][sx] = 0;
	while (!pq.empty()) {
		int cost = pq.top().first;
		int x = pq.top().second.first;
		int y = pq.top().second.second;
		pq.pop();
		if (aa[y][x] == 'F') {
			cout << cost / (MAX * MAX) << " " << cost % (MAX * MAX) << "\n";
			return 0;
		}
		if (d[y][x] < cost || vis[y][x])
			continue;
		vis[y][x] = true;
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx<0 || ny<0 || nx>=M || ny>=N || vis[ny][nx])
				continue;
			int nCost = cost + a[ny][nx];
			if (nCost < d[ny][nx]) {
				d[ny][nx] = nCost;
				pq.push({ nCost, {nx, ny} });
			}
		}
	}
}