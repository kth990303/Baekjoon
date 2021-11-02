// 210406 #6549 히스토그램에서 가장 큰 직사각형 Platinum V
// Divide_Conquer
// like segtree idea + from middle to edge (h is different)
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 100001;
ll N, a[MAX];
ll solve(int s, int e) {
	if (s == e)
		return a[s];
	ll mid = (s + e) / 2;
	ll ret = max(solve(s, mid), solve(mid + 1, e));
	// middle to edge
	ll lo = mid, hi = mid + 1;
	ll h = min(a[lo], a[hi]);
	ret = max(ret, (hi - lo + 1) * h);
	while (s <= lo && hi <= e) {
		if (lo > 0 && hi < N - 1 && a[lo - 1] >= a[hi + 1]) {
			h = min(h, a[--lo]);
		}
		else if (hi == e) {
			h = min(h, a[--lo]);
		}
		else
			h = min(h, a[++hi]);
		ret = max(ret, (hi - lo + 1) * h);
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	while (cin >> N) {
		if (!N) break;
		for (int i = 0; i < N; i++) {
			cin >> a[i];
		}
		cout << solve(0, N - 1) << "\n";
	}
}