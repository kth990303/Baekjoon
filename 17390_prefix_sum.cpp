// 201207 #17390 이건 꼭 풀어야 해! Silver III
// 기본적인 prefix_sum
// prefix_sum과 segtree의 차이는 update가 없다는 점!
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 300001;
int N, Q, a[MAX], sum[MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + N + 1);	// 비내림차순 정렬, a[1]부터 시작
	for (int i = 1; i <= N; i++) {
		sum[i] = sum[i - 1] + a[i];	// 누적합 배열
	}
	while (Q--) {
		int s, e;
		cin >> s >> e;
		cout << sum[e] - sum[s - 1] << "\n";	// 누적합 알고리즘
	}
}