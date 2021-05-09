// 210509 #21735 ´«µ¢ÀÌ ±¼¸®±â Silver II
// backtracking
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 101;
int N, M, a[MAX], ans;
void solve(int size, int cur, int time) {
	if (cur == N || !time) {
		ans = max(ans, size);
		return;
	}
	if (cur + 1 <= N) {
		solve(size + a[cur + 1], cur + 1, time - 1);
	}
	if (cur + 2 <= N) {
		solve(size / 2 + a[cur + 2], cur + 2, time - 1);
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	solve(1, 0, M);
	cout << ans << "\n";
}