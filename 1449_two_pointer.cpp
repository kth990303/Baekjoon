// 201227 #1449 수리공 항승 Silver III
// 투포인터: O(N)
// 왜 알고리즘 분류에 투포인터가 없는지 의문.
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1001;
int N, L, ans, a[MAX];
//수리공 항승 : 그리디에서 가져온 문제인데, 그닥 그리디적인 면은 많이 없다.
//일단 sort해주고, 물이 새는 곳 a, b가 L미만으로 떨어져있으면 같은 테이프로
//붙일 수 있다.예를 들어 N = 7, L = 2, 1 2 3 5 6 100 101이면, 0.5~2.5, 2.5~3.5,
//4.5~6.5, 99.5~101.5 이렇게 총 4개가 된다. (뜬금없이 테케를 하나 더 줘버렸다)
//딱히 그리디라 할만한 건 없고, 정렬을 잘하고 구현 잘하면 될 것 같다.참고로
//저는 투포인터로 풀었습니다...
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> L;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	sort(a, a + N);
	int s = 0, e = 1;
	// e가 끝부분 달릴 때까지
	while (e < N) {
		if (a[e] - a[s] >= L) {
			ans++;
			s = e;
		}
		else
			e++;
	}
	// 마지막에 e가 끝일 때엔 ans++ 안해줬으므로
	cout << ans + 1 << "\n";
}