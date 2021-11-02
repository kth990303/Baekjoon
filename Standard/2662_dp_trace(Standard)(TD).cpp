// 210306 #2662 기업투자 Gold III
// like #2618(Platinum V dp)
// knapsack dp+trace
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 21;
const int MAX_D = 301;
int N, M, d[MAX_D][MAX], a[MAX_D][MAX], tr[MAX_D][MAX];
int dp(int price, int cur) {
	int& ret = d[price][cur];
	if (ret != -1)
		return ret;
	if (cur == M)
		return ret = 0;
	ret = dp(price, cur + 1);
	// ret -> i=0 search
	for (int i = 1; i <= N; i++) {
		if (price - i >= 0) {
			int tmp = dp(price - i, cur + 1) + a[i][cur];
			// if this is right ans, update table
			if (ret < tmp) {
				ret = tmp;
				tr[price][cur] = i;
			}
		}
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		for (int j = 0; j < M; j++) {
			cin >> a[num][j];
		}
	}
	memset(d, -1, sizeof(d));
	// 0'th ~ k'th all cases search
	cout << dp(N, 0) << "\n";
	for (int i = 0; i < M; i++) {
		cout << tr[N][i] << " ";
		N -= tr[N][i];
	}
}