// 210811 #12019 悼酒府规 没家! Gold I
// dp
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
const int MAX = 101;
const int INF = 0x3f3f3f3f;
int N, M, a[MAX], d[MAX][2001][11];
vector<int> ans;
int dp(int cur, int n, int cnt) {
	if (N - cur < M - cnt)
		return INF;
	if (cur >= N)
		return cnt == M ? 0 : INF;
	int& ret = d[cur][n][cnt];
	if (ret != -1)
		return ret;
	ret = dp(cur + 1, n + a[cur], cnt) + n * a[cur];
	if (cnt < M)
		ret = min(ret, dp(cur + 1, a[cur], cnt + 1));
	return ret;
}
void trace(int n, int cnt) {
	for (int i = 0; i < N; i++) {
		if (cnt == M)
			break;
		if (d[i + 1][n + a[i]][cnt] + n*a[i]>= d[i + 1][a[i]][cnt + 1]) {
			n = a[i];
			cout << i << " ";
			cnt++;
		}
		else
			n += a[i];
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	memset(d, -1, sizeof(d));
	cout << dp(0, 0, 0) << "\n";
	trace(0, 0);
}