// 210322 #18243 Small World Network Silver II
// All relationships && N<=100 -> floyd
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 101;
int N, K, d[MAX][MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	memset(d, 0x3f3f3f, sizeof(d));
	for (int i = 1; i <= N; i++) {
		d[i][i] = 0;
	}
	for (int i = 0; i < K; i++) {
		int a, b;
		cin >> a >> b;
		d[a][b] = 1;
		d[b][a] = 1;
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
		for (int j = 1; j <= N; j++) {
			ans = max(d[i][j], ans);
		}
	}
	if (ans <= 6)
		cout << "Small World!\n";
	else
		cout << "Big World!\n";
}