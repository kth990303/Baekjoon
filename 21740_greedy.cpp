// 210510 #21740 도도의 수학여행 Platinum III
// string sort, greedy
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100001;
int N;
string tmp, M;
vector<string> v;
bool cmp(string s1, string s2) {
	return s1 + s2 > s2 + s1;
}
bool cmp2(string s1, string s2) {
	if (s1.length() == s2.length())
		return stoi(s1) > stoi(s2);
	return s1.length() > s2.length();
}
void check() {
	reverse(tmp.begin(), tmp.end());
	for (int j = 0; j < tmp.length(); j++) {
		if (tmp[j] == '9')
			tmp[j] = '6';
		else if (tmp[j] == '6')
			tmp[j] = '9';
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		tmp = to_string(n);
		check();
		if (cmp2(tmp, M))
			M = tmp;
		v.push_back(tmp);
	}
	v.push_back(M);
	sort(v.begin(), v.end(), cmp);
	string ans;
	for (int i = 0; i < v.size(); i++) {
		ans += v[i];
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		if (ans[i] == '6')
			cout << "9";
		else if (ans[i] == '9')
			cout << "6";
		else
			cout << ans[i];
	}
}