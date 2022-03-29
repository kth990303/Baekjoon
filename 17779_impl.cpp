// 220230 #17779 게리맨더링 2 Gold IV
// impl
// important index range
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
const int MAX = 23;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e16;
const int MOD = 1e9 + 7;
int N, a[MAX][MAX], b[MAX][MAX], X, Y,d1,d2,ans = INF;
bool flag;
int dx[4] = { 1,1,-1,-1 };
int dy[4] = { -1,1,1,-1 };
int check(int cnt) {
	if (cnt < d1)return 0;
	if (cnt < d1 + d2)return 1;
	if (cnt < 2 * d1 + d2)return 2;
	return 3;
}
void setMap() {
	for (int y = 1; y <= N; y++) {
		for (int x = 1; x <= N; x++) {
			if (y != Y - d1 && y != Y + d2 && b[y][x]) {
				flag = !flag;
				continue;
			}
			else if (b[y][x] == 5)continue;
			else if (flag)b[y][x] = 5;
			else if (x <= X + d1 && y < Y)b[y][x] = 1;
			else if (x > X + d1 && y <= Y - d1 + d2)b[y][x] = 2;
			else if (x < X + d2 && y >= Y)b[y][x] = 3;
			else if (x >= X + d2 && y > Y - d1 + d2)b[y][x] = 4;
		}
	}
}
void solve() {
	for (d1 = 1; d1 <= Y - 1; d1++) {
		for (d2 = 1; d2 <= N - Y; d2++) {
			if (X + d1 + d2 > N)break;
			memset(b, 0, sizeof(b));
			b[Y][X] = 5;
			int nx = X, ny = Y;
			for (int i = 0; i < 2*(d1 + d2); i++) {
				nx += dx[check(i)];
				ny += dy[check(i)];
				b[ny][nx] = 5;
			}
			flag = false;
			setMap();
			int c[6] = { 0 };
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					c[b[i][j]] += a[i][j];
				}
			}
			int M = max({ c[1],c[2],c[3],c[4],c[5] });
			int m = min({ c[1],c[2],c[3],c[4],c[5] });
			ans = min(ans, M - m);
		}
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 2; i < N; i++) {
		for (int j = 1; j < N; j++) {
			X = j, Y = i;
			solve();
		}
	}
	cout << ans;
}