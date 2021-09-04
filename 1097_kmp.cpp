// 210904 #1097 마법의단어 Platinum V
// kmp (like #4354)
// O(N*N!)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
const int MAX = 9;
int N, K, ans;
vector<string> v;
vector<int> v2;
string s;
bool visit[MAX];
vector<int> fail() {
	int j = 0;
	vector<int> pi(s.length(), 0);
	for (int i = 1; i < s.length(); i++) {
		while (j > 0 && s[i] != s[j]) {
			j = pi[j - 1];
		}
		if (s[i] == s[j])
			pi[i] = ++j;
	}
	return pi;
}
void solve(int cur, int cnt) {
	// if next_permutation, then press(v) -> not correct
	if (cnt == N) {
		s.clear();
		for (int i = 0; i < N; i++)
			s += v[v2[i]];
		vector<int> pi = fail();
		int res = 0, n = s.length();
		if (!pi[n - 1] || pi[n - 1] % (n - pi[n - 1]))
			res = 1;
		else
			res = n / (n - pi[n - 1]);
		if (res == K)
			ans++;
		return;
	}
	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			visit[i] = true;
			v2.push_back(i);
			solve(i, cnt + 1);
			v2.pop_back();
			visit[i] = false;
		}
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string str;
		cin >> str;
		v.push_back(str);
	}
	sort(all(v));
	cin >> K;
	solve(0, 0);
	cout << ans << "\n";
}