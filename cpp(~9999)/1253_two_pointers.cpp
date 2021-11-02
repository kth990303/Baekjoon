// 210321 #1253 ¡¡¥Ÿ Gold III
// two_pointers
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 2001;
int N, a[MAX], ans;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	sort(a, a + N);
	for (int i = 0; i < N; i++) {
		// a[i]>a[0], a[1], ... a[i-1]
		// but, 0 0 0 0 0 0 exception case
		// so, s=0, e=N-1
		int s = 0, e = N - 1;
		while (s < e) {
			// not same number
			if (s == i) {
				s++;
				continue;
			}
			// not same number
			if (e == i) {
				e--;
				continue;
			}
			if (a[s] + a[e] == a[i]) {
				ans++;
				break;
			}
			if (a[s] + a[e] > a[i])
				e--;
			else
				s++;
		}
	}
	cout << ans << "\n";
}