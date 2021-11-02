// 210508 #4949 ±ÕÇüÀâÈù¼¼»ó Silver IV
// (), {}, [] -> close with partner('}' partner: '{')
// so use stack
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
string s;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	while (1) {
		getline(cin, s);
		if (s == ".")
			break;
		stack<char> st;
		bool flag = true;
		for (int i = 0; i < s.length(); i++) {
			if (s[i] != '(' && s[i] != ')' && s[i] != '[' && s[i] != ']')
				continue;
			if (s[i] == '(' || s[i] == '[')
				st.push(s[i]);
			else if (s[i] == ')' && !st.empty() && st.top() == '(')
				st.pop();
			else if (s[i] == ']' && !st.empty() && st.top() == '[')
				st.pop();
			else {
				flag = false;
				break;
			}
		}
		if (!st.empty())
			flag = false;
		if (flag)
			cout << "yes\n";
		else
			cout << "no\n";
	}
}