// 200911 #11053 LIS 1 Silver II
// 바텀업 방식 O(N^2)
// 둘 다 연습해놓자
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1001;
int N, a[MAX], cache[MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	fill(cache, cache + MAX, 1);
	int ans = 1;	// 항상 길이는 1. 이거 안하면 99%에서 틀림
	for (int i = 1; i < N; i++) {
		for (int j = 0; j < i; j++) {
			// 이전 수보다 크면서, 길이가 더 길어지는 경우
			if (a[i] > a[j] && cache[i] < cache[j] + 1) {
				cache[i] = cache[j] + 1;
			}
		}
		// 가장 긴 길이로
		ans = max(ans, cache[i]);
	}
	cout << ans << "\n";
}