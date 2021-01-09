// 210109 #1405 ¹ÌÄ£·Îº¿ Gold V
// backtracking (N<=14: 4 * 3^(n-1) = 6millions)
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 30;
double N, d[4], ans;
vector<double> v;
int a[MAX][MAX], dx[4] = { 0,0,-1,1 }, dy[4] = { -1,1,0,0 };
bool visit[MAX][MAX];
void solve(int cur, int x, int y, double k) {
	visit[y][x] = true;
	if (cur == N) {
		ans += k;
		return;
	}
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (!visit[ny][nx] && d[i]) {
			k *= d[i];
			solve(cur + 1, nx, ny, k);
			// set in its original form
			// backtracking key point
			k /= d[i];
			visit[ny][nx] = false;
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cout << fixed;
	cout.precision(15);

	cin >> N;
	for (int i = 3; i >= 0; i--) {
		cin >> d[i];
		d[i] /= (double)100;
	}
	solve(0, 14, 14, 1);
	cout << ans << "\n";
}