// 210103 #2435 기상청 인턴 신현수 Silver V
// prefix_sum(Silver III), Bruth_force(Silver V)
// bruthforce: O(N^2), prefix_sum (O(N))
// N<=100
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 101;
int N, K, a[MAX], s[MAX], ans = -1e9 - 7; // 주의
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		s[i] = s[i - 1] + a[i];
	}
	for (int i = K; i <= N; i++) {
		ans = max(ans, s[i] - s[i - K]);
	}
	cout << ans << "\n";
}