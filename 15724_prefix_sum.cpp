// 210411 #15724 ÁÖÁö¼ö Gold V
// prefix_sum with two-dimensial array
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1025;
int N, M, K, a[MAX][MAX], p[MAX][MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++) {
			cin >> a[i][j];
			p[i][j] = p[i - 1][j] + p[i][j - 1] + a[i][j];
			p[i][j] -= p[i - 1][j - 1];
		}
	}
	cin >> K;
	while (K--) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		cout << p[x2][y2] - p[x1 - 1][y2] - p[x2][y1 - 1]
			+ p[x1 - 1][y1 - 1] << "\n";
	}
}