// 210910 #2847 게임을 만든 동준이 Silver IV
// greedy
// order by DESC
#include <iostream>
using namespace std;
const int MAX = 101;
int N, a[MAX], ans;
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = N - 2; i >= 0; i--) {
		if (a[i] <= a[i + 1] - 1)
			continue;
		ans += a[i] - (a[i + 1] - 1);
		a[i] = a[i + 1] - 1;
	}
	cout << ans << "\n";
}