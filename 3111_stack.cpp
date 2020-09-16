// 200917 #3111 검열 Platinum V
// 정작 stack 헤더는 하나도 안 필요함
// 다만, stack의 pop을 구현해야 됨
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string a, t, rev;
string s1, s2;
bool check(bool stat) {
	if (stat) {
		if (s1.length() < a.length())
			return false;
		for (int i = 0; i < a.length(); i++) {
			if (s1[s1.length() - i - 1] != rev[i])
				return false;
		}
		s1.erase(s1.end()-a.length(), s1.end());
	}
	else {
		if (s2.length() < a.length())
			return false;
		for (int i = 0; i < a.length(); i++) {
			if (s2[s2.length() - i - 1] != a[i])
				return false;
		}
		s2.erase(s2.end() - a.length(), s2.end());
	}
	return true;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> a >> t;
	// a의 거꾸로 버전 만들어놓아야 함
	for (int i = a.length() - 1; i >= 0; i--) {
		rev += a[i];
	}
	int s = 0, e = t.length() - 1;
	bool stat = true;
	while (s <= e) {
		// 앞에서부터 파악
		if (stat) {
			s1 += t[s];
			s++;
		}
		// 뒤에서부터 파악
		else {
			s2 += t[e];
			e--;
		}
		// s1이나 s2에 a가 있는지 파악하고
		// 있으면 그만큼 지움 (erase)
		// 그리고 stat은 !stat으로
		if(check(stat))
			stat = !stat;
	}
	string ans;
	// 합쳐지면서 또 a가 생길 수 있음
	// 따라서 한 번 더 진행
	for (int i = s2.length()-1; i>=0; i--) {
		s1 += s2[i];
		check(true);
	}
	cout << s1 << "\n";
}