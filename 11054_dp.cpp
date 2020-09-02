// 200902 #11054 가장 긴 바이토닉 Gold III
// DP, LIS의 응용
// 처음엔 lower_bound로 했다가 그 과정이 필요없음을 깨달음
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1000;
int N;
int a[MAX];
int d[MAX], d2[MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < N; i++) {
		d[i] = 1;	// 모든 숫자는 길이 1
		for (int j = 0; j <= i; j++) {
			// a[i]가 수가 더 크다면,
			if (a[j] < a[i] && d[i] < d[j] + 1) {
				// dp를 갱신해줌
				d[i] = d[j] + 1;
			}
		}
	}
	// 바이토닉 수열이므로 역으로도 수행
	for (int i = N - 1; i >= 0; i--) {
		d2[i] = 1;
		for (int j = N - 1; j >= i; j--) {
			if (a[j] < a[i] && d2[i] < d2[j] + 1) {
				d2[i] = d2[j] + 1;
			}
		}
	}
	int ans = 0;
	// 가운데 숫자는 중복되므로 1을 빼줘야됨
	for (int i = 0; i < N; i++) {
		ans = max(ans, d[i] + d2[i] - 1);
	}
	cout << ans << "\n";
}