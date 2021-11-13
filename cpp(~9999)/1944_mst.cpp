// 211113 #1944 º¹Á¦·Îº¿ Gold II
// bfs + mst (many start point -> mst)
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
const int MAX = 253;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e16;
const int MOD = 1e9 + 7;
int N, M, ans, p[MAX], cnt;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
char a[MAX][MAX];
bool vis[MAX][MAX];
vector<pii> v;
vector<pi> point;
map<pi, int> m;
int find(int a) {
	if (a == p[a])
		return a;
	return p[a] = find(p[a]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)return false;
	if (a > b)swap(a, b);
	p[b] = a;
	return true;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	M++;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			a[i][j] = s[j];
			if (a[i][j] == 'S' || a[i][j] == 'K') {
				a[i][j] = 'K';
				m[pi(j, i)] = point.size();
				point.push_back({ j,i });
			}
		}
	}
	for (int i = 0; i < M; i++) {
		p[i] = i;
		queue<pii> q;
		int sx = point[i].first;
		int sy = point[i].second;
		q.push({ 0,{point[i]} });
		memset(vis, false, sizeof(vis));
		vis[sy][sx] = true;
		while (!q.empty()) {
			int cost = q.front().first;
			int x = q.front().second.first;
			int y = q.front().second.second;
			q.pop();
			if (a[y][x] == 'K') {
				v.push_back({ cost, {i,m[{x,y}]} });
			}
			for (int i = 0; i < 4; i++) {
				int nx = x + dx[i];
				int ny = y + dy[i];
				if (nx < 0 || ny < 0 || nx >= N || ny >= N)continue;
				if (!vis[ny][nx] && a[ny][nx] != '1') {
					vis[ny][nx] = true;
					q.push({ cost + 1,{nx,ny} });
				}
			}
		}
	}
	sort(all(v));
	for (int i = 0; i < v.size(); i++) {
		int n1 = v[i].second.first;
		int n2 = v[i].second.second;
		int cost = v[i].first;
		if (find(n1) != find(n2)) {
			merge(n1, n2);
			ans += cost;
		}
	}
	bool flag = true;
	for (int i = 0; i < M; i++) {
		if (find(i) != find(0)) {
			flag = false;
			break;
		}
	}
	if (!flag)cout << -1 << "\n";
	else cout << ans << "\n";
}