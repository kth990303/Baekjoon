// 211108 #3114 사과와바나나 Gold II
// prefix_sum + dp
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> pii;
const int MAX = 1511;
const double INF = 0x3f3f3f3f;
const int LNF = 1e16;
const int MOD = 1e9 + 7;
int R, C, a[MAX][MAX], b[MAX][MAX], ap[MAX][MAX], bp[MAX][MAX];
int d[MAX][MAX];
int dp(int x, int y) {
	if (y > R || x > C) return 0;
	if (y == R && x == C) return 0;
	int& ret = d[y][x];
	if (ret != -1)
		return ret;
	ret = 0;
	if (y + 1 <= R)
		ret = max(ret, dp(x, y + 1) + ap[y + 1][x - 1]);
	if (x + 1 <= C)
		ret = max(ret, dp(x + 1, y) + bp[y - 1][x + 1]);
	if (y + 1 <= R && x + 1 <= C)
		ret = max(ret, dp(x + 1, y + 1) + ap[y + 1][x] + bp[y][x + 1]);
	return ret;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> R >> C;
	for (int i = 1; i <= R; i++) {
		for (int j = 1; j <= C; j++) {
			string s;
			cin >> s;
			if (s[0] == 'A')
				a[i][j] = stoi(s.substr(1));
			else 
				b[i][j] = stoi(s.substr(1));
			ap[i][j] = ap[i][j - 1] + a[i][j];
			bp[i][j] = bp[i - 1][j] + b[i][j];
		}
	}
	memset(d, -1, sizeof(d));
	cout << dp(1, 1) << "\n";
}