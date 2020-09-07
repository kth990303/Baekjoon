// #3020 개똥벌레 Gold V
// 1. prefix_sum 2. Binary Search
// crocus님 블로그로 prefix_sum 방법 참고
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 500001;
const int INF = 1000000007;
int N, H, ans, cnt;
int a[MAX], b[MAX], totalA[MAX], totalB[MAX], total[MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> H;
	for (int i = 0; i < N / 2; i++) {
		int aVal, bVal;
		cin >> bVal >> aVal;
		a[aVal]++;
		b[bVal]++;
	}
	// 누적 합으로 충돌하는 장애물 개수
	// 어차피 i보다 높은 거는 다 충돌하니까
	totalA[H] = a[H];
	totalB[H] = b[H];
	for (int i = H - 1; i >= 1; i--) {
		totalA[i] = a[i] + totalA[i + 1];
		totalB[i] = b[i] + totalB[i + 1];
	}
	ans = INF;
	for (int i = 1; i <= H; i++) {
		total[i] = totalA[i] + totalB[H - i + 1];
		// 더 적게 충돌하면 구간 갱신
		if (total[i] < ans) {
			cnt = 1;
			ans = total[i];
		}
		// 같은 개수로 맞을 경우 cnt증가
		else if (total[i] == ans) {
			cnt++;
		}
	}
	cout << ans << " " << cnt << "\n";
}