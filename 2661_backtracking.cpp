// 210103 #2661 좋은수열 Gold IV
// backtracking O(N^3)
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int N;
string s = "1";
bool check(string s, int len) {
	// O(N^2)
	// substr: O(s.length())
	// check from mid of length: because of adjacency
	for (int i = 1; i <= len / 2; i++) {
		if (s.substr(len - i * 2, i) == s.substr(len - i, i))
			return false;
	}
	return true;
}
// O(N * 3N^2) = o(3N^3) 
void solve(string s) {
	if (s.length() == N) {
		cout << s << "\n";
		exit(0);
	}
	for (int i = 1; i <= 3; i++) {
		// if s[s.length()-1]==s[s.length()]
		if (s[s.length() - 1] == i + '0')
			continue;
		// if put to_string(i), can this be a good sequence?
		if (check(s + to_string(i), s.length() + 1))
			solve(s + to_string(i));
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	solve(s);
}