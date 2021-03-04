// 210304 #1328 °íÃþºôµù Gold I
// dp + math: it looks like easy, but difficult
// it looks like bottom-up is easier than top-down 
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 101;
const int INF = 1e9 + 7;
typedef long long ll;
ll N, L, R, d[MAX][MAX][MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	d[1][1][1] = 1;
	d[2][2][1] = d[2][1][2] = 1;
	cin >> N >> L >> R;
	for (int i = 3; i <= N; i++) {
		for (int j = 1; j <= L; j++) {
			for (int k = 1; k <= R; k++) {
				// base case
				if (i == j && k == 1 || i == k && j == 1) {
					d[i][j][k] = 1;
					continue;
				}
				d[i][j][k] = d[i - 1][j][k] * (ll)(i - 2);
				d[i][j][k] %= INF;
				d[i][j][k] += d[i - 1][j - 1][k] + d[i - 1][j][k - 1];
				d[i][j][k] %= INF;
			}
		}
	}
	cout << d[N][L][R] << "\n";
}