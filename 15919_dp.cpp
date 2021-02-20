// 210220 #15919 사자는 여행왕이야!! Gold II
// dp: why? min(maximum)
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int MAX = 1001;
const int INF = 1e9 + 7;
int N, M, d[MAX][MAX];
vector<pair<int, int>> v;
int dp(int cur, int day) {
	int& ret = d[cur][day];
	if (ret != -1)
		return ret;
	if (cur == M)
		return ret = N - day;
	ret = dp(cur + 1, day);
	if (day < v[cur].first) {
		ret = min(ret, max((v[cur].first - 1) - day,
			dp(cur + 1, v[cur].second)));
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	v.resize(M);
	for (int i = 0; i < M; i++) {
		cin >> v[i].first >> v[i].second;
	}
	memset(d, -1, sizeof(d));
	sort(v.begin(), v.end());
	cout << dp(0, 0) << "\n";
}