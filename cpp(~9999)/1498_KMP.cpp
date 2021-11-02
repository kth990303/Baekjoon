// 200921 #1498 주기문 Platinum V
// 문자열 제곱 (4354)랑 거의 동일한 문제
// KMP의 실패함수를 이용.
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s, p;
// 전형적인 kmp의 실패함수
vector<int> fail() {
	int j = 0;
	vector<int> pi(s.length(), 0);
	for (int i = 1; i < s.length(); i++) {
		while (j > 0 && s[i] != s[j]) {
			j = pi[j - 1];
		}
		if (s[i] == s[j])
			pi[i] = ++j;
	}
	return pi;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> s;
	vector<int> v = fail();
	int n = s.length() - 1;
	for (int i = 1; i < s.length(); i++) {
		// 주기를 이루려면 실패함수가 0이면 안된다
		// 0인 경우는 반복되는 접두사, 접미사가 아예 없는 경우
		if (!v[i])
			continue;
		// 현재 길이 % (반복되지 않는 길이)가 0인 경우
		// 주기를 이루는 주기문이 존재
		if (!((i+1) % ((i+1)-v[i]))) {
			cout << i + 1 << " " << (i+1) / (i+1 - v[i]) << "\n";
		}
	}
}