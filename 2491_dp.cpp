// 210106 #2491 ¼ö¿­ Silver II
// Silver...II? why not Silver IV?
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100001;
int N, a[MAX], d[MAX], d2[MAX], ans = 1;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	fill(d, d + MAX, 1);
	fill(d2, d2 + MAX, 1);
	for (int i = 1; i < N; i++) {
		if (a[i] >= a[i - 1]) {
			d[i] = d[i - 1] + 1;
		}
		if (a[i] <= a[i - 1]) {
			d2[i] = d2[i - 1] + 1;
		}
		ans = max({ ans, d[i], d2[i] });
	}
	cout << ans << "\n";
}