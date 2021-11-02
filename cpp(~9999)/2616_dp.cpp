// 210214 #2616 소형기관차 Gold IV
// 맞왜틀 계속 했던 dp + prefix_sum
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
const int MAX = 50001;
int N, M, a[MAX], s[MAX], d[4][MAX];
// top-down 좋아
int dp(int item, int cur) {
	int& ret = d[item][cur];
	if (ret != -1)
		return ret;
	if (!item)
		return ret = 0;
	if (cur < M)
		return ret = s[cur + 1];
	ret = dp(item, cur - 1);
	if (item > 0 && cur - M >= 0) {
		ret = max(ret, dp(item - 1, cur - M) 
			+ s[cur + 1] - s[cur + 1 - M]);
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
		s[i + 1] = s[i] + a[i];
	}
	cin >> M;
	memset(d, -1, sizeof(d));
	cout << dp(3, N - 1) << "\n";
}