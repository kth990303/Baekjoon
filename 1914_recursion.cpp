// 210118 #1914 하노이 탑 Silver II
// fuckin BigInteger (2^100-1)
#include <iostream>
#include <string>
using namespace std;
const int MOD = 1e9;
int N, K, num[101];
void solve(int h, int cur, int mid, int next) {
	if (h == 0)
		return;
	// cur: now, next: destination
	// 1->2
	solve(h - 1, cur, next, mid);
	cout << cur << " " << next << "\n";
	// 2->3
	solve(h - 1, mid, cur, next);
}
void bigNum(int n) {
	int cnt = 0;
	num[0] = 1;
	while (n--) {
		for (int i = 0; i <= cnt; i++) {
			num[i] *= 2;
		}
		for (int i = 0; i <= cnt; i++) {
			// if Integer is bigger than 1e9,
			// MOD보다 클 때엔 MOD로 나눠주고, 다음 자릿수 num[i+1]에
			// 나눈 몫을 저장해준다.
			if (num[i] >= MOD) {
				// num[i+1]: (10*i ~ 10*i + 9)th digit
				// 즉, num[i+1]의 값은 10*i~10*i+9번째 자리수 저장
				if (!num[i + 1])
					cnt++;
				num[i + 1] += num[i] / MOD;
				num[i] %= MOD;
			}
		}
	}
	for (int i = cnt; i >= 0; i--) {
		// 처음에는 반드시 9자리가 아니어도 되지만,
		// 중간에 9자리가 아닌 경우는 끝까지 채워줘야한다.
		if (i!=cnt && to_string(num[i]).length() != 9) {
			for (int j = 0; j < 9 - to_string(num[i]).length(); j++) {
				cout << "0";
			}
		}
		// 끝자리에서 -1을 해줘야 한다.
		if (!i)
			cout << num[i] - 1 << "\n";
		else
			cout << num[i];
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	bigNum(N);
	// 재귀 이용하면 끝
	if (N <= 20) {
		solve(N, 1, 2, 3);
	}
}