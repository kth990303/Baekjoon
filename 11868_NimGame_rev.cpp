// 200903 #11868 NimGame II Platinum IV
// 베스킨라빈스와 반대. 나중에 가져간 사람이 진다.
// 이문제 풀때마다 술게임하고 싶어진다...
// 이런 경우는 예외처리 없이 님의 합만 따지면됨
#include <iostream>
using namespace std;
const int MAX = 101;
int N, p[MAX], ans;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> p[i];
		ans ^= p[i];
	}
	// 님의 합이 0인 경우 지므로
	if (!ans)
		cout << "cubelover" << "\n";
	// 님의 합을 매턴마다 0으로 후딱 만들어버리기만 하면되므로
	else
		cout << "koosaga" << "\n";
}