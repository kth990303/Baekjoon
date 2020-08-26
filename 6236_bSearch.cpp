#include <iostream>
#include <algorithm>
using namespace std;
const int INF = 2000000000;
int N, M, a[100000];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	int s = 0, e = INF;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}

	while (s<=e) {
		int cnt = 1;
		int mid = (s + e) / 2;
		int sum = 0;
		for (int i = 0; i < N; i++) {
			// 하루 지출액보다 인출량이 적으면 안됨
			if (a[i] > mid) {
				cnt = INF;
				break;
			}
			if (sum + a[i] > mid) {
				cnt++;
				sum = 0;
			}
			sum += a[i];
		}
		// 1일 때 예외처리를 잘 해줘야 한다
		if (M == 1) {
			cout << sum;
			return 0;
		}
		// 최소값을 구하는 문제
		// 같은 경우 중 최소일 때를 구해야 하므로
		// 같은 경우는 e를 줄이자
		if (cnt <= M)
			e = mid - 1;
		else
			s = mid + 1;
	}
	// 마지막에 s=e일 때도 e=mid-1이 들어갔으므로
	// e+1을 출력해줘야 정답
	cout << e + 1;
}