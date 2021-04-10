// 210411 #1727 커플 만들기 Gold III
// dp with min process
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#define all(v) v.begin(), v.end()
using namespace std;
const int MAX = 1001;
const int INF = 1e9 + 7;
int N, M, d[MAX][MAX];
vector<int> v1, v2;
int dp(int n1, int n2) {
	int& ret = d[n1][n2];
	if (n2 >= M)
		return ret = 0;
	else if (n1 >= N)
		return ret = INF;
	if (ret != -1)
		return ret;
	ret = dp(n1 + 1, n2 + 1) + abs(v1[n1] - v2[n2]);
	ret = min(ret, dp(n1 + 1, n2));
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	v1.resize(N); v2.resize(M);
	for (int i = 0; i < N; i++) {
		cin >> v1[i];
	}
	for (int i = 0; i < M; i++) {
		cin >> v2[i];
	}
	sort(all(v1));
	sort(all(v2));
	if (N < M) {
		swap(N, M);
		swap(v1, v2);
	}
	memset(d, -1, sizeof(d));
	cout << dp(0, 0) << "\n";
}