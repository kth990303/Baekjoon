// 201209 #10159 저울 Gold III
// N의 크기도 100으로 작고, 모든 경우의 우위를 파악->floyd(O(N^3))
// Q. 왜 topological sort(위상정렬)로는 불가능?
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 101;
// 0x7f로 하다간, 오버플로우가 발생할 수 있음.
// 2*INF 계산이 포함되므로, 여기선 0x3f로 지정.
const int INF = 0x3f;
int N, M, d[MAX][MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	// 길이 없는 경우: cost를 무한으로
	// 여기서는, 우열을 따질 수 없는 경우
	// 일단 초기화는 전부 INF로
	memset(d, INF, sizeof(d));
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		// 우열을 따질 수 있을 시, 길이 존재
		// 여기서는 d[a][b]=1로 지정.
		d[a][b] = 1;
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				// 바로 이부분 때문에 INF=0x3f
				// 모든 경로를 파악하는 floyd 이용
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		int ans = 0;
		for (int j = 1; j <= N; j++) {
			if (i == j)
				continue;
			// d[i][j], d[j][i]모두 우열을 가릴 수 없어야 답에 포함
			else if (d[i][j] >= INF && d[j][i] >= INF)
				ans++;
		}
		cout << ans << "\n";
	}
}