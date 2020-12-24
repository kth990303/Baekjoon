// 201223 #15961 회전초밥 Gold V
// 슬라이딩 윈도우, 투포인터
// O(N+K)
#include <iostream>
#include <algorithm>
const int MAX = 3003001;
using namespace std;
int N, D, K, C, ans, a[MAX], d[3001];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> D >> K >> C;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	int ret = 0;
	for (int i = 0; i < K; i++) {
		if (!d[a[i]])
			ret++;
		d[a[i]]++;
		a[i + N] = a[i];
	}
	for (int i = 0; i < N; i++) {
		if (!d[C])
			ans = max(ans, ret + 1);
		else
			ans = max(ans, ret);
		if (--d[a[i]] == 0)
			ret--;
		if (!d[a[i + K]])
			ret++;

		d[a[i + K]]++;
	}
	cout << ans << "\n";
}