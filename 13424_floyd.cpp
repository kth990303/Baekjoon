// 201218 #13424 비밀모임 Gold V
// 0x3f는 int로 63... memset(비트)이랑 int랑 차이난다는 점 주의...!!!
// N이 작아서 O(N^3) 풀이의 플로이드도 가능.
// 다익스트라를 여러번 돌리기보다 이게 더 쉬움. 시작점이 여러개!
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
const int INF = 0x3f;
const int MAX = 101;
using namespace std;
int N, M, K, d[MAX][MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		memset(d, INF, sizeof(d));
		cin >> N >> M;
		for (int i = 1; i <= N; i++) {
			d[i][i] = 0;
		}
		for (int i = 0; i < M; i++) {
			int a, b, cost;
			cin >> a >> b >> cost;
			d[a][b] = cost;
			d[b][a] = cost;
		}
		for (int k = 1; k <= N; k++) {
			for (int i = 1; i <= N; i++) {
				for (int j = 1; j <= N; j++) {
					d[i][j] = min({d[i][j], d[i][k] + d[k][j]});
				}
			}
		}
		cin >> K;
		vector<int> start;
		start.resize(K);
		for (int i = 0; i < K; i++) {
			cin >> start[i];
		}
		// int ans=INF로 했다가 맞왜틀...ㅋㅋㅋ
		int ans = 1e9 + 7, idx = 0;
		for (int i = 1; i <= N; i++) {
			int dis = 0;
			for (auto j: start) {
				dis += d[j][i];
			}
			if (ans > dis) {
				idx = i;
				ans = dis;
			}
		}
		cout << idx << "\n";
	}
}