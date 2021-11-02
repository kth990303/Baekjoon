// 200908 #1956 운동 Gold IV
// 다익스트라: O(V*ElogV)=>V^3logV
// 플로이드 와샬: O(V^3)
// 또한 도로가 단방향, 사이클 여부 확인 -> 플로이드가 더 적합
// 주의: memset INF= 0x3f3f3f3f
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
const int MAX = 401;
const int INF = 0x3f3f3f3f;
int V, E;
int d[MAX][MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> V >> E;
	memset(d, INF, sizeof(d));
	for (int i = 1; i <= E; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		d[a][b] = cost;
	}
	for (int k = 1; k <= V; k++) {
		for (int i = 1; i <= V; i++) {
			for (int j = 1; j <= V; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	int ans = INF;
	for (int i = 1; i <= V; i++) {
		ans = min(ans, d[i][i]);
	}
	if (ans == INF)
		cout << -1 << "\n";
	else
		cout << ans << "\n";
}