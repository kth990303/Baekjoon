// 210920 #1213 팰린드롬만들기 Silver IV
// impl, string
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define all(v) (v).begin(), (v).end()
using namespace std;
int N, cnt[26], n;
string s, ans;
vector<char> v;
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> s;
	N = s.size();
	for (int i = 0; i < N; i++) {
		cnt[s[i] - 'A']++;
	}
	char flag = 'a';
	for (int i = 0; i < 26; i++) {
		if (cnt[i] % 2) {
			n++;
			flag = (char)(65 + i);
		}
		if (n > 1) {
			cout << "I'm Sorry Hansoo\n";
			return 0;
		}
		for (int j = 0; j < cnt[i] / 2; j++)
			v.push_back((char)(65 + i));
	}
	sort(all(v));
	for (int i = 0; i < v.size(); i++)
		cout << v[i];
	if (flag != 'a')
		cout << flag;
	for (int i = v.size() - 1; i >= 0; i--)
		cout << v[i];
}