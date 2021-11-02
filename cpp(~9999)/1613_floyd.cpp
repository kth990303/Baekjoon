// 200907 #1613 역사 Gold III
// dfs나 bfs로 하면 TLE O(SV^2)=50000 * 400^2
// 한번의 케이스인 경우는 Floyd보다 빠르나, 이 경우는 5만개의 케이스
// floyd는 O(V^3)이나 이 경우는 V가 작음+슬라이딩윈도우로 인한 적은 메모리
// 게다가 사건 전후관계 따지기에 딱임 (because of 이차원배열~)
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 401;
const int INF = 1000000007;
int N, K, d[MAX][MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		d[a][b] = 1;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!d[i][j])
				d[i][j] = INF;
		}
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	int s;
	cin >> s;
	for (int i = 0; i < s; i++) {
		int a, b;
		cin >> a >> b;
		if (d[a][b] == INF && d[b][a] == INF)
			cout << "0\n";
		else if (d[a][b] == INF)
			cout << "1\n";
		else
			cout << "-1\n";
	}
}