// 210214 #16434 �巡�� �� ���� Gold III
// Why Gold III? -> binary search solution is Gold III
// But, this is O(N) -> Silver III
#include <iostream>
#include <algorithm>
typedef long long ll;
using namespace std;
const int MAX = 123457;
ll N, S, ans = 1, maxHP = 1;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> S;
	for (int i = 0; i < N; i++) {
		ll ch, s, hp;
		cin >> ch >> s >> hp;
		// ������ ��
		if (ch == 1) {
			ans += s * ((hp - 1) / S);
			maxHP = max(maxHP, ans);
		}
		// ������ �ִ� ��
		else {
			S += s;
			ans -= hp;
			if (ans <= 0)
				ans = 1;
		}
	}
	cout << maxHP << "\n";
}