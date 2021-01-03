// 210103 #14888 연산자 끼워넣기 Silver I
// Bruth_force, Backtracking O(4^N)
// Samsung SWEA
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 12;
int N, a[MAX], op[MAX], maxAns = -1e9 - 7, minAns = 1e9 + 7;
// Like dfs (recursion: bruth_force)
void solve(int n, int num) {
	if (n == N) {
		maxAns = max(maxAns, num);
		minAns = min(minAns, num);
		return;	// return without executing below code
	}
	if (op[0]) {
		op[0]--;
		solve(n + 1, num + a[n]);
		op[0]++;	// return to original state
	}
	if (op[1]) {
		op[1]--;
		solve(n + 1, num - a[n]);
		op[1]++;
	}
	if (op[2]) {
		op[2]--;
		solve(n + 1, num * a[n]);
		op[2]++;
	}
	if (op[3]) {
		op[3]--;
		solve(n + 1, num / a[n]);
		op[3]++;
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < 4; i++) {
		cin >> op[i];
	}
	solve(1, a[0]);
	cout << maxAns << "\n" << minAns << "\n";
}