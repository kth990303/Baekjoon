// 210114 #2225 ÇÕºÐÇØ Gold V
// dp(bottom-up) O(KN^2)
#include <iostream>
using namespace std;
const int MAX = 201;
const int MOD = 1e9;
int N, K, d[MAX][MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	d[0][0] = 1;
	for (int i = 1; i <= K; i++) {
		for (int j = 0; j <= N; j++) {
			for (int k = 0; k <= j; k++) {
				d[j][i] += d[j - k][i - 1];
				d[j][i] %= MOD;
			}
		}
	}
	cout << d[N][K] << "\n";
}