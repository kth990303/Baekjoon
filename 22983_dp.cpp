// 210830 #22983 조각체스판 Gold II
// O(NM) BU dp
// icpc.me/1915 hard version
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
const int MAX = 3001;
ll N, M, d[MAX][MAX], ans;
char a[MAX][MAX];
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < M; j++) {
			a[i][j] = s[j];
			d[i][j] = 1;
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i && j) {
				if (a[i][j] == a[i - 1][j - 1] && a[i][j] != a[i - 1][j]
					&& a[i][j] != a[i][j - 1]) {
					d[i][j] = min({ d[i - 1][j], d[i][j - 1], d[i - 1][j - 1] });
					d[i][j]++;
				}
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ans += d[i][j];
		}
	}
	cout << ans << "\n";
}