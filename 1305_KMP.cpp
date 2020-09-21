// 200921 #1305 광고 Platinum V
// KMP의 fail function 응용 문제
#include <iostream>
#include <string>
#include <vector>
using namespace std;
string s;
int n;
// 전형적인 kmp의 실패함수
vector<int> fail() {
	int j = 0;
	vector<int> pi(s.length(), 0);
	for (int i = 1; i < s.length(); i++) {
		while (j > 0 && s[i] != s[j]) {
			j = pi[j - 1];
		}
		// 만약 같은 문자가 나오면 (접두사=접미사)
		if (s[i] == s[j])
			pi[i] = ++j;
	}
	return pi;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> n >> s;
	vector<int> pi = fail();
	// 접두사가 같은 부분이 나오면
	// 같은 부분이 길어질수록 광고는 그만큼 짧아질 수 있음
	// 광고판에서 접두사 부분이 추가로 보여지기 때문
	cout << n - pi[n - 1] << "\n";
}