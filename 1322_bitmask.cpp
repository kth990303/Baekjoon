// 210127 #1322 X와 K Gold IV
// bitmask
#include <iostream>
using namespace std;
typedef unsigned long long ll;
ll X, Y, K;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> X >> K;
	int cnt = 0;
	// K(2) 의 자릿수
	while (K >> cnt) {
		cnt++;
	}
	int j = 0;
	for (int i = 0; i < cnt; i++) {
		// X의 자릿수가 0일 때까지 찾기
		while (X & (1LL << j))
			j++;
		// K번째 큰 수 = K(2)가 1일 때 한꺼번에 처리
		// 그러면 K번째 수를 깔끔하게 찾음. 많이 어려웠음.
		if (K & (1LL << i))
			Y += (1LL << j);
		// 그 다음 자릿수로
		j++;
	}
	cout << Y << "\n";
}