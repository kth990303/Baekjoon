// 210801 #21758 ²Üµû±â Silver II
// greedy + prefix_sum
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100001;
int N, a[MAX], p[MAX], ans;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		p[i] = p[i - 1] + a[i];
	}
	for (int i = 2; i <= N; i++) {
		ans = max(ans, 2 * p[N] - a[1] - a[i] - p[i]);
	}
	for (int i = 1; i < N; i++) {
		ans = max(ans, p[N - 1] - a[i] + p[i - 1]);
	}
	for (int i = 2; i < N; i++) {
		ans = max(ans, p[i] - a[1] + p[N - 1] - p[i - 1]);
	}
	cout << ans << "\n";
}