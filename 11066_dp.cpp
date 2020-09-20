// 200921 #11066 파일 합치기 Gold III
// top-down 방식
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 501;
const int INF = 1000000007;
int N, a[MAX], d[MAX][MAX];
int dp(int s, int e) {
	int& ret = d[s][e];
	if (ret != -1)
		return ret;
	if (s == e)
		return ret = 0;
	int sum = 0;
	for (int i = s; i <= e; i++) {
		sum += a[i];
	}
	ret = INF;
	// 점점 범위를 좁힌다.
	for (int i = s; i < e; i++) {
		ret = min(ret, dp(s, i) + dp(i + 1, e) + sum);
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		memset(d, -1, sizeof(d));
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> a[i];
		}
		cout << dp(0, N - 1) << "\n";
	}
}