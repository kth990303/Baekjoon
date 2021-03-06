// 200909 #11780 巴稽戚球2 Gold IV
// 鯵昔旋生稽 嬢形頗製
// 井稽猿走 乞砧 窒径馬糠稽 魚稽 煽舌背丘醤喫.
// 坦製拭 設 照彊臣虞辞 霜庚伊事税 green55還 坪球 凧壱敗
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
		// 旭精 井稽昔汽 cost亜 希 笛 惟 級嬢神澗 井酔亜 赤製
		// せせせせせせ.....
		if (cost < d[a][b]) {
			d[a][b] = cost;
			path[a][b] = b;	// 井稽 煽舌
		}
	}
	for (int k = 1; k <= N; k++) {
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (d[i][k] + d[k][j] < d[i][j]) {
					d[i][j] = d[i][k] + d[k][j];
					path[i][j] = path[i][k];	// 井稽 煽舌
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