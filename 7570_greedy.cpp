// 210131 #7570 줄세우기 Gold IV
// Greedy -> Make LIS
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1000001;
const int INF = 1e9 + 7;
int N, ans, cnt[MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num;
		// LIS
		cnt[num] = cnt[num - 1] + 1;
		ans = max(ans, cnt[num]);
	}
	// make lis
	cout << N - ans << "\n";
}