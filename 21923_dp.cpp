// 210801 #21923 °î¿¹ºñÇà Gold IV
// dp
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAX = 1001;
const ll INF = 1e15;
ll N, M, a[MAX][MAX], d[MAX][MAX][2];
bool visit[MAX][MAX][2];
// upper
ll dp1(int y, int x) {
	if (y == N - 1 && !x)
		return a[y][x];
	ll& ret = d[y][x][0];
	if (visit[y][x][0])
		return ret;
	ret = -INF;
	visit[y][x][0] = true;
	if (y < N)
		ret = max(ret, dp1(y + 1, x) + a[y][x]);
	if (x)
		ret = max(ret, dp1(y, x - 1) + a[y][x]);
	return ret;
}
// lower
ll dp2(int y, int x) {
	if (y == N - 1 && x == M - 1)
		return a[y][x];
	ll& ret = d[y][x][1];
	if (visit[y][x][1])
		return ret;
	visit[y][x][1] = true;
	ret = -INF;
	if (y < N)
		ret = max(ret, dp2(y + 1, x) + a[y][x]);
	if (x < M)
		ret = max(ret, dp2(y, x + 1) + a[y][x]);
	return ret;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> a[i][j];
		}
	}
	ll ans = -INF;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ans = max(ans, dp1(i, j) + dp2(i, j));
		}
	}
	cout << ans << "\n";
}