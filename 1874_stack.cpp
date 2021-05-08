// 210508 #1874 스택 수열 Silver III
// use stack && input immdiate process
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
const int MAX = 100001;
int N, a[MAX], num = 1;
stack<int> st;
vector<char> ans;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		if (st.empty() && num <= N) {
			ans.push_back('+');
			st.push(num++);
		}
		while (!st.empty() && st.top() < a[i]) {
			ans.push_back('+');
			st.push(num++);
		}
		while (!st.empty() && st.top() > a[i]) {
			ans.push_back('-');
			st.pop();
		}
		if (st.empty() || !st.empty() && st.top() != a[i]) {
			cout << "NO\n";
			return 0;
		}
		else {
			ans.push_back('-');
			st.pop();
		}
	}
	for (auto i : ans) {
		cout << i << "\n";
	}
}