// 210519 #16934 게임 닉네임 Platinum IV
// map solution -> I think it's Silver I
// I guess it's O(N*length)
#include <iostream>
#include <algorithm>
#include <string>
#include <map>
using namespace std;
const int MAX = 100001;
map<string, int> m, m2;
int N;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string tmp;
		tmp.clear();
		string s;
		cin >> s;
		m2[s]++;
		for (int j = 0; j < s.length(); j++) {
			tmp += s[j];
			m[tmp]++;
		}
		if (m2[s] > 1) {
			cout << s << m2[s] << "\n";
		}
		else {
			tmp.clear();
			bool flag = false;
			for (int j = 0; j < s.length(); j++) {
				tmp += s[j];
				if (m[tmp] == 1) {
					cout << tmp << "\n";
					flag = true;
					break;
				}
			}
			if (!flag) {
				cout << s << "\n";
			}
		}
	}
}