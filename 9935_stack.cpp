// 210514 #9935 ¹®ÀÚ¿­ Æø¹ß Gold IV
// stack == vector, but stack cannot approach begin, middle index
// string(a, b)->str(a, a+1, a+2, ... , b)
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
const int MAX = 1000001;
string s, p;
vector<char> v;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> s >> p;
	for (int i = 0; i < s.length(); i++) {
		v.push_back(s[i]);
		while (v.size() >= p.length() && string(v.end()-p.length(), v.end())==p) {
			for (int j = 0; j < p.length(); j++) {
				v.pop_back();
			}
		}
	}
	if (v.empty()) {
		cout << "FRULA";
		return 0;
	}
	for (auto i : v) {
		cout << i;
	}
}