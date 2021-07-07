// 210707 #14601 »þ¿ö½Ç ¹Ù´Ú ±ò±â(Large)
// L-tromino tiling: divide_conquer
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
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 128;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
int K, X, Y, a[MAX][MAX], n;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
void check(int sx, int sy, int ex, int ey, int k) {
	bool flag = false;
	for (int i = sy; i <= ey; i++) {
		for (int j = sx; j <= ex; j++) {
			if (a[i][j]) {
				flag = true;
				break;
			}
		}
		if (flag) break;
	}
	if (!flag) {
		if (!k)
			a[ey][ex] = n;
		else if (k == 1)
			a[ey][sx] = n;
		else if (k == 2)
			a[sy][ex] = n;
		else
			a[sy][sx] = n;
	}
}
void solve(int sx, int sy, int ex, int ey) {
	int size = (ex - sx + 1) * (ey - sy + 1);
	if (size == 4) {
		++n;
		for (int i = sy; i <= ey; i++) {
			for (int j = sx; j <= ex; j++) {
				if (a[i][j])
					continue;
				a[i][j] = n;
			}
		}
		return;
	}
	++n;
	int midx = (sx + ex) / 2;
	int midy = (sy + ey) / 2;
	check(sx, sy, midx, midy, 0);
	check(midx + 1, sy, ex, midy, 1);
	check(sx, midy + 1, midx, ey, 2);
	check(midx + 1, midy + 1, ex, ey, 3);

	solve(sx, sy, midx, midy);
	solve(midx + 1, sy, ex, midy);
	solve(sx, midy + 1, midx, ey);
	solve(midx + 1, midy + 1, ex, ey);
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> K >> X >> Y;
	X--; Y--;
	Y = (1 << K) - 1 - Y;
	a[Y][X] = -1;
	solve(0, 0, (1 << K) - 1, (1 << K) - 1);
	for (int i = 0; i < (1 << K); i++) {
		for (int j = 0; j < (1 << K); j++) {
			cout << a[i][j] << " ";
		}
		cout << "\n";
	}
}