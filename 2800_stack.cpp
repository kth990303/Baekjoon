// 210515 #2800 °ýÈ£ Á¦°Å Gold V
// () -> use stack (vector)
// backtracking
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int MAX = 201;
vector<pair<int, int>> ans;
vector<string> res;
string s;
bool visit[MAX];
void solve(int cur) {
	if (cur == ans.size()) {
		string str;
		for (int j = 0; j < s.length(); j++) {
			if (visit[j])
				continue;
			str += s[j];
		}
		if (str != s)
			res.push_back(str);
		return;
	}
	solve(cur + 1);
	visit[ans[cur].first] = true;
	visit[ans[cur].second] = true;
	solve(cur + 1);
	visit[ans[cur].first] = false;
	visit[ans[cur].second] = false;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> s;
	vector<pair<char, int>> st;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] == '(' || s[i] == ')') {
			st.push_back({ s[i], i });
		}
		if (st.size() >= 2 && st[st.size()-2].first=='(' 
			&& st[st.size()-1].first==')') {
			ans.push_back({ st[st.size() - 2].second, st[st.size() - 1].second });
			st.pop_back();
			st.pop_back();
		}
	}
	solve(0);
	sort(res.begin(), res.end());
	res.erase(unique(res.begin(), res.end()), res.end());
	for (auto i : res) {
		cout << i << "\n";
	}
}