// 200830 #13699 점화식 Silver IV
// dp, 카탈란 수
// 2nCn - 2nCn+1
#include <iostream>
using namespace std;
typedef long long ll;
ll d[72][72];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	ll N;
	cin >> N;
	for (int i = 1; i <= 71; i++) {
		for (int j = 1; j <= i; j++) {
			if (j == 1 || j == i) {
				d[i][j] = 1;
			}
			else {
				d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
			}
		}
	}
	cout << d[2 * N + 1][N + 1] - d[2 * N + 1][N + 2] << "\n";
}