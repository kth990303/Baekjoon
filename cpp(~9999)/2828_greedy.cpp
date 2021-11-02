// 201216 #2828 사과담기게임 Bronze I
// 생각해야될 게 많은 그리디
/*
6 3 4
6
5
1
3
ans: 6

10 3 6
6
5
1
3
4
9
ans: 12
*/
#include <iostream>
#include <algorithm>
using namespace std;
int N, M, K, ans;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;
	pair<int, int> k = { 1,M };	// 바구니 처음과 끝
	while (K--) {
		int apple;
		cin >> apple;

		if (k.first <= apple && apple <= k.second)
			continue;
		else if (apple < k.first) {
			ans += k.first - apple;
			k.first = apple;
			k.second = k.first + M - 1;
		}
		else {
			ans += apple - k.second;
			k.second = apple;
			k.first = k.second - M + 1;
		}
	}
	cout << ans << "\n";
}