#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1001;
const int INF = 1000000007;
int N, a[MAX], d[MAX];
int dp(int cur) {
	// 왜 N-1일 때도 return 0을 하는가?
	// 오른쪽 끝이면 이동하지 않으므로.
	if (cur >= N - 1)
		return 0;
	int& ret = d[cur];
	if (ret != -1)
		return ret;
	ret = INF;
	for (int i = 1; i <= a[cur]; i++) {
		// 왜 1을 더했는가?
		// 점프하면서 1을 더해진 값이랑 비교를 해야됨
		ret = min(ret, dp(cur + i) + 1);
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	fill(d, d + N, -1);
	// 왜 ==가 아니고 >=인가?
	// 갈 수 없는 칸에 1 더해질 수도 있음
	if (dp(0) >= INF)
		cout << -1 << "\n";
	else
		cout << dp(0) << "\n";
}