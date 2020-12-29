// 201229 #14465 소가 길을 건너간 이유 5 Silver II
// O(N^2)은 시간초과. O(N)으로 풀어야 됨.
// two_pointer 이용. 알고리즘 분류는 이분탐색, 스위핑, 누적합
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 100001;
const int INF = 1e9 + 7;
int N, K, B, ans;
bool a[MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K >> B;
	while (B--) {
		int n;
		cin >> n;
		a[n] = true;
	}
	int s = 1, e = K;
	for (int i = s; i <= e; i++) {
		if (a[i])
			ans++;
	}
	// 신호등 전체 정상작동시키려 할 때
	if (K == N) {
		cout << ans << "\n";
		return 0;
	}
	// K<N 이어서 e 증가시켜서 탐색해야 할 때
	int cnt = ans;
	e++;
	if (a[e])
		cnt++;
	while (1) {
		if (e - s + 1 == K) {
			ans = min(ans, cnt);
			if (e == N)
				break;
			e++;
			// 다음 신호등이 고장이면 개수 추가
			if (a[e])
				cnt++;
			continue;
		}
		else if (e - s + 1 > K) {
			if (a[s])
				cnt--;
			s++;
		}
		else {
			e++;
			if (a[e])
				cnt++;
		}
	}
	cout << ans << "\n";
}