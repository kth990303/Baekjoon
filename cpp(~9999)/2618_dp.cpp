// 210221 #2618 °æÂûÂ÷ Platinum V
// trace is annoying... thats why platinum V DP
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int MAX = 1002;
struct police {
	int x, y;
};
police n1[MAX], n2[MAX];
int N, W, d[MAX][MAX];
bool visit[MAX][MAX];
int dp(int p1, int p2) {
	int& ret = d[p1][p2];
	if (ret != -1)
		return ret;
	if (p1 == W || p2 == W)
		return ret = 0;
	int next = max(p1, p2) + 1;
	int d1 = abs(n1[p1].x - n1[next].x) + abs(n1[p1].y - n1[next].y);
	int d2 = abs(n2[p2].x - n2[next].x) + abs(n2[p2].y - n2[next].y);
	int c1 = dp(next, p2) + d1;
	int c2 = dp(p1, next) + d2;
	// finishing dp and check visit table
	// so it's correct visit table
	if (c1 < c2) {
		ret = c1;
	}
	else {
		// p2 À¯¸®
		ret = c2;
		visit[p1][p2] = true;
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> W;
	n1[0] = { 0,0 }; n2[0] = { N - 1, N - 1 };
	for (int i = 1; i <= W; i++) {
		cin >> n1[i].x >> n1[i].y;
		n1[i].x--; n1[i].y--;
		n2[i].x = n1[i].x;
		n2[i].y = n1[i].y;
	}
	memset(d, -1, sizeof(d));
	cout << dp(0, 0) << "\n";
	// this is very difficult..
	for (int i = 0, j = 0; max(i, j) < W; ) {
		if (visit[i][j]) {
			cout << 2 << "\n";
			j = max(i, j) + 1;
		}
		else {
			cout << 1 << "\n";
			i = max(i, j) + 1;
		}
	}
}