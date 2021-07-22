// 210722 #1389 케빈 베이컨의 6단계 법칙
// floyd O(N^3)
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
const int MAX = 101;
const int INF = 0x3f3f3f3f;
int N, M, d[MAX][MAX];
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	memset(d, INF, sizeof(d));
	while (M--) {
		int a, b;
		cin >> a >> b;
		d[a][b] = d[b][a] = 1;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	int ret = INF, ans = 0;
	for (int i = 1; i <= N; i++) {
		int sum = 0;
		for (int j = 1; j <= N; j++) {
			if (i == j)
				continue;
			sum += d[i][j];
		}
		if (sum < ret) {
			ret = sum;
			ans = i;
		}
	}
	cout << ans << "\n";
}