// #16968 차량번호판1 Bronze II
// 1. 백트래킹 풀이
// 사실 백트래킹이라 하기도 뭐하다.
#include <iostream>
#include <string>
using namespace std;
int ans[4], idx;
void check(char c1, char c2) {
	if (c1 == 'c') {
		ans[idx] = 26;
		// 중복될 경우
		if (c2 == 'c')
			ans[idx]--;
	}
	else {
		ans[idx] = 10;
		if (c2 == 'd')
			ans[idx]--;
	}
	idx++;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	string s;
	cin >> s;
	int cnt = 1;
	for (int i = 0; i < s.length(); i++) {
		// 백트래킹인 이유
		// 첫번째 글자와 두번째 글자에 따라
		check(s[i], s[i + 1]);
		// 결과가 바뀐다.
		// 물론 여기서는 그 외 결과로 접근하진 않으므로
		// 엄밀히 따지자면 백트래킹이라 하기도 좀 그렇긴 하다.
		cnt *= ans[i];
	}
	cout << cnt;
}