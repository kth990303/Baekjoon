#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 101;
int N, K, a[MAX], ans = -1e9 - 7;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i <= N - K; i++) {
		int s = 0;
		for (int j = i; j < i + K; j++) {
			s += a[j];
		}
		ans = max(ans, s);
	}
	cout << ans << "\n";
}