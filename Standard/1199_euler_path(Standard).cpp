// 210325 #1199 오일러 회로 Gold II
// Euler_path(Standard) -> 한붓그리기
#include <iostream>
using namespace std;
const int MAX = 1001;
const int INF = 1e9 + 7;
int N, a[MAX][MAX], degree[MAX];
void solve(int cur) {
	for (int i = 1; i <= N; i++) {
		if (a[cur][i]) {
			a[cur][i]--;
			a[i][cur]--;
			solve(i);
		}
	}
	cout << cur << " ";
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> a[i][j];
			degree[j] += a[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		if (degree[i] % 2) {
			cout << -1 << "\n";
			return 0;
		}
	}
	solve(1);
}