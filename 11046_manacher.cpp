// 210307 #11046 ÆÓ¸°µå·Ò?? Platinum V
// manacher's algorithm standard II
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 2000002;
// not string. (1<=a[idx].length()<=6)
int N, M, a[MAX], p[MAX];
void manacher(int size) {
	int r = 0, c = 0;
	for (int i = 0; i < size; i++) {
		if (i <= r)
			p[i] = min(p[c * 2 - i], r - i);
		while (i - p[i] - 1 >= 0 && i + p[i] + 1 < size && a[i - p[i] - 1] == a[i + p[i] + 1]) {
			p[i]++;
		}
		if (r < i + p[i]) {
			r = i + p[i];
			c = i;
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		a[i * 2] = -1;
		cin >> a[i * 2 + 1];
	}
	a[N * 2] = -1;
	manacher(N * 2 + 1);
	cin >> M;
	while (M--) {
		int lo, hi;
		cin >> lo >> hi;
		int mid = ((lo * 2 - 1) + (hi * 2 - 1)) / 2;
		if (p[mid] >= hi - lo + 1) {
			cout << 1 << "\n";
		}
		else
			cout << 0 << "\n";
	}
}