// 210331 #2157 ¿©Çà Gold IV
// similar as #20925 maplestory dp
// if we can N'th, return ret=0 else return ret=-INF
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 301;
const int INF = 1e9 + 7;
int N, M, K, d[MAX][MAX], ans;
vector<pair<int, int>> v[MAX];
int dp(int cur, int cnt) {
	int& ret = d[cur][cnt];
	if (ret != -1)
		return ret;
	if (cur == N - 1)
		return ret = 0;
	if (cnt >= M)
		return ret = -INF;
	ret = -INF;
	for (auto i : v[cur]) {
		if (i.second > cur)
			ret = max(ret, dp(i.second, cnt + 1) + i.first);
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;
	for (int i = 0; i < K; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		a--; b--;
		if (a < b)
			v[a].push_back({ cost, b });

	}
	memset(d, -1, sizeof(d));
	cout << dp(0, 1) << "\n";
}