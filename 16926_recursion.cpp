// 210625 #16926 배열돌리기1 Silver III
// I think it's Silver II ~ silver I
// recursion
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 301;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
int N, M, R, a[MAX][MAX], ori;
int dx[4] = { 0,1,0,-1 };
int dy[4] = { 1,0,-1,0 };
void dfs(int val, int x, int y, int dir) {
	int tmp = a[y][x];
	a[y][x] = val;
	int nx = x + dx[dir];
	int ny = y + dy[dir];
	if (nx == ori && ny == ori && dir == 3)
		return;
	if (nx >= ori && ny >= ori && nx < M-ori && ny < N-ori)
		dfs(tmp, nx, ny, dir);
	else if (dir != 3) {
		nx = x + dx[dir + 1];
		ny = y + dy[dir + 1];
		dfs(tmp, nx, ny, dir + 1);
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M >> R;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a[i][j];
		}
	}
	int t = min(N, M) / 2;
	while (R--) {
		for (int i = 0; i < t; i++) {
			ori = i;
			dfs(a[i][i + 1], i, i, 0);
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}