#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1001;
int N, a[MAX], d[MAX], ans;
int dp(int cur) {
	int& ret = d[cur];	// dp table
	if (ret != -1)
		return ret;
	if (cur == N)
		return ret = 0;
	ret = 0;
	int m = a[cur], M = a[cur];
	// 자기 자신에 대한 정보를 담고,
	// 다음 턴으로 넘어가야 된다.
	// 따라서 cur+1부터 적용하면 안된다.
	for (int i = cur+1; i < N; i++) {
		m = min(m, a[i]);
		M = max(M, a[i]);
		ret = max(ret, dp(i) + M - m);	// M-m을 더해줘야 한다.
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
	fill(d, d + MAX, -1);
	cout << dp(0) << "\n";
}