// 210507 #21600 °è´Ü Gold V
// two_pointers
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100001;
int N, a[MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	int s = 0, e = 0, ans = 1;
	while (s != N - 1) {
		if (a[e] >= e - s + 1) {
			ans = max(ans, e - s + 1);
			e++;
		}
		else
			s++;
	}
	cout << ans << "\n";
}