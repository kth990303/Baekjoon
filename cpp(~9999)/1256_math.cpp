// 210125 #1256 »çÀü Gold III
// combination + Math
#include <iostream>
#include <string>
using namespace std;
const int MAX = 101;
typedef unsigned long long ll;
ll N, M, K, d[MAX * 2][MAX];
void init() {
	d[0][0] = 1;
	for (int i = 1; i <= N + M; i++) {
		for (int j = 0; j <= i; j++) {
			if (!j)
				d[i][j] = 1;
			else
				d[i][j] = d[i - 1][j - 1] + d[i - 1][j];
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;
	init();
	ll num = d[N + M][M];
	if (K > num) {
		cout << -1 << "\n";
		return 0;
	}
	string ans;
	while (1) {
		if (!N || !M)
			break;
		// if 'z' -> start is 'a~~' case +1
		if (K > d[N + M - 1][N - 1]) {
			ans += 'z';
			K -= d[N + M - 1][N - 1];
			M -= 1;
		}
		else {
			ans += 'a';
			N -= 1;
		}
	}
	if (N) {
		for (int i = 0; i < N; i++)
			ans += 'a';
	}
	if (M) {
		for (int i = 0; i < M; i++)
			ans += 'z';
	}
	cout << ans << "\n";
}