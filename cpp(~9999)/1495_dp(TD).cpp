// 200921 #1495 기타리스트 Silver I
// 볼륨에 따라서 값이 달라짐
// 탑다운 방식, O(NM)
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 1000000007;
const int MAX = 1001;
int a[MAX], d[100][MAX];
int N, S, M;
int dp(int cur, int volume) {
	int& ret = d[cur][volume];
	if (ret != -1)
		return ret;
	if (cur == N)
		return ret = volume;
	ret = -INF;
	if (volume - a[cur] >= 0)
		ret = max(ret, dp(cur + 1, volume - a[cur]));
	if (volume + a[cur] <= M)
		ret = max(ret, dp(cur + 1, volume + a[cur]));
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> S >> M;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	memset(d, -1, sizeof(d));
	cout << max(-1, dp(0, S)) << "\n";
}