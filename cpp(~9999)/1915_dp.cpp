// 210225 #1915 가장 큰 정사각형 Gold V
// dp bottom_up
// bruth-force? No, only check d[i-1][j], d[i][j-1], d[i-1][j-1]
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int MAX = 1001;
int N, M, a[MAX][MAX], d[MAX][MAX], ans;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			a[i][j] = s[j] - '0';
			if (a[i][j]) {
				d[i][j] = 1;
				ans = 1;
			}
		}
	}
	for (int i = 1; i < N; i++) {
		for (int j = 1; j < M; j++) {
			if (a[i][j]) {
				if (d[i - 1][j] && d[i][j - 1] && d[i - 1][j - 1]) {
					d[i][j] = min({ d[i - 1][j], d[i][j - 1], d[i - 1][j - 1] }) + 1;
				}
			}
			ans = max(ans, d[i][j] * d[i][j]);
		}
	}
	cout << ans << "\n";
}