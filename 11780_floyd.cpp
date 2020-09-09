// 200909 #11780 플로이드2 Gold IV
// 개인적으로 어려웠음
// 경로까지 모두 출력하므로 따로 저장해둬야됨.
// 처음에 잘 안떠올라서 질문검색의 green55님 코드 참고함
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 101;
const int INF = 1000000007;
int d[MAX][MAX], N, M;
int path[MAX][MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < MAX; i++) {
		for (int j = 0; j < MAX; j++) {
			if (i == j)
				d[i][j] = 0;
			else
				d[i][j] = INF;
		}
	}
	for (int i = 0; i < M; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		// 같은 경로인데 cost가 더 큰 게 들어오는 경우가 있음
		// ㅋㅋㅋㅋㅋㅋ.....
		if (cost < d[a][b]) {
			d[a][b] = cost;
			path[a][b] = b;	// 경로 저장
		}
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (d[i][k] + d[k][j] < d[i][j]) {
					d[i][j] = d[i][k] + d[k][j];
					path[i][j] = path[i][k];	// 경로 저장
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (d[i][j] == INF)
				cout << 0 << " ";
			else
				cout << d[i][j] << " ";
		}
		cout << "\n";
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (i == j || d[i][j] == INF)
				cout << "0";
			else {
				vector<int> v;
				int cur = i;
				while (cur != j) {
					v.push_back(cur);
					cur = path[cur][j];
				}
				v.push_back(j);
				cout << v.size() << " ";
				for (auto i : v)
					cout << i << " ";
			}
			cout << "\n";
		}
	}
}