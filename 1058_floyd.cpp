// 210319 #1058 Ä£±¸ Silver I
// later, it can be Silver V
// floyd solution
// N<=50, O(N^3) , floyd : lots of dfs and similar disjoint set
#include <iostream>
#include <string>
#include <cstring>
using namespace std;
const int MAX = 51;
int N, a[MAX][MAX], ans;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	memset(a, 0x3f3f3f, sizeof(a));
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			if (i == j)
				a[i][j] = 0;
			else if (s[j] == 'Y')
				a[i][j] = 1;
		}
	}
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		int ret = 0;
		for (int j = 0; j < N; j++) {
			if (a[i][j] == 1 || a[i][j] == 2)
				ret++;
		}
		ans = max(ret, ans);
	}
	cout << ans << "\n";
}