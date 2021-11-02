// 210107 #2110 공유기 설치 Silver I
// binary_search
// 생각은 쉬운데 구현이 조금 까다로움.
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 200001;
int N, C, a[MAX];
int solve(int s, int e) {
	while (s<=e) {
		int mid = (s + e) / 2, cnt = 1;
		int k = a[0];
		for (int i = 1; i < N; i++) {
			if (a[i] >= k + mid) {
				k = a[i];
				cnt++;
			}
		}
		if (cnt >= C)
			s = mid + 1;
		else
			e = mid - 1;
	}
	return s - 1;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> C;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	sort(a, a + N);
	cout << solve(0, a[N - 1]) << "\n";
}