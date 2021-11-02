// 200904 #4358 생태학 Gold IV
// Trie 연습하려 했는데 그냥 map으로 해버림...
// map, 소수점 네자리, eof 연습문제라 치자
// 다음엔 꼭 trie로 해보자
#include <iostream>
#include <map>
#include <string>
using namespace std;
map<string, int> m;
int N;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);
	string s;
	while (getline(cin, s)) {
		m[s]++;
		N++;
	}
	cout << fixed;
	cout.precision(4);
	for (auto it = m.begin(); it != m.end(); it++) {
		cout << (*it).first << " " << 
			(double)((double)(*it).second / N) * 100 << "\n";
	}
}