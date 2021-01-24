// 210124 #16120 PPAP Gold IV
// implementation + greedy
// transfer -> P cnt ++
#include <iostream>
#include <string>
using namespace std;
string s;
bool flag = true;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == 'P') {
			cnt++;
		}
		else {
			if (cnt >= 2 && s[i + 1] == 'P') {
				cnt--;	// PPA(P) -> P
				i++;	// (P) No search.
			}
			else
				flag = false;
		}
	}
	if (cnt == 1 && flag)
		cout << "PPAP\n";
	else
		cout << "NP\n";
}