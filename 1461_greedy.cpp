// 210124 #1461 µµ¼­°ü Gold V
// Greedy + Sort + implementation
#include <iostream>
#include <algorithm>
#include <vector>
//10 4
//- 39 - 37 - 28 - 29 - 6 2 11 17 23 29
//ans: 113
using namespace std;
const int MAX = 10001;
int a[MAX], N, M, ans;
int v1[MAX], v2[MAX];
bool cmp(int a, int b) {
	return a > b;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	int cnt1 = 0, cnt2 = 0;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		if (a[i] > 0)
			v1[++cnt1] = a[i];
		else
			v2[++cnt2] = a[i];
	}
	// % -> 1~cnt1
	sort(v1 + 1, v1 + cnt1 + 1);
	// 1~cnt2
	sort(v2 + 1, v2 + cnt2 + 1, cmp);
	for (int i = cnt1 % M; i <= cnt1; i += M) {
		if (!i)
			continue;
		ans += v1[i] * 2;
	}
	for (int i = cnt2 % M; i <= cnt2; i += M) {
		if (!i)
			continue;
		ans += abs(v2[i]) * 2;
	}
	ans -= max(v1[cnt1], abs(v2[cnt2]));
	cout << ans << "\n";
}