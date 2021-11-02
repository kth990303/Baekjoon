// 200912 #2458 키 순서 Gold IV
// 키의 전후관계: 플로이드 
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 501;
const int INF = 0x3f;
int N, M, d[MAX][MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	memset(d, INF, sizeof(d));
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		d[a][b] = 1;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		bool flag = true;
		for (int j = 1; j <= N; j++) {
			// 자신을 제외하고, 연결이 안된 경우 있으면 false
			if (i != j) {
				if (d[i][j] >= INF && d[j][i] >= INF) {
					flag = false;
					break;
				}
			}
		}
		if (flag)
			ans++;
	}
	cout << ans << "\n";
}