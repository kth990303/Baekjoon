// 210110 #1748 수 이어쓰기 1 Silver III
// Math
#include <iostream>
#include <cmath>
using namespace std;
int N, n, ans;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	if (N < 10) {
		cout << N << "\n";
		return 0;
	}
	n = N;
	int tmp = 0, idx = 0;
	for (int i = 1; i <= 9; i++) {
		if (N >= pow(10, i)) {
			tmp += 9 * pow(10, i - 1) * i;
			n -= 9 * pow(10, i - 1);
		}
		else {
			idx = i;
			break;
		}
	}
	ans += tmp;
	ans += n * idx;
	cout << ans << "\n";
}