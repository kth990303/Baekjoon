// 210507 #21600 °è´Ü Gold V
// dp  (I think dp, two_pointers all ~Silver I)
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 100001;
int N, a[MAX], d[MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		d[i] = 1;
	}
	int ans = 1;
	for (int i = 1; i < N; i++) {
		d[i] = min(a[i], d[i - 1] + 1);
		ans = max(ans, d[i]);
	}
	cout << ans << "\n";
}