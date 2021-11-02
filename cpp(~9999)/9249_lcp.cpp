// 210814 #9249 최장 공통 부분 문자열 Platinum III
// LCS O(Nlg^2(N))
#include <iostream>
#include <algorithm>
#include <string>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
const int MAX = 200001;
int N, M, t, sa[MAX], group[MAX], lcp[MAX], r[MAX], tmp[MAX];
string s, A, B, res;
bool cmp(int x, int y) {
	if (group[x] == group[y]) {
		x += t; y += t;
		if (x < N && y < N)
			return group[x] < group[y];
		return x > y;
	}
	return group[x] < group[y];
}
void getSA() {
	for (int i = 0; i < N; i++) {
		sa[i] = i;
		group[i] = s[i] - 'a';
	}
	for (t = 1; t <= N; t *= 2) {
		sort(sa, sa + N, cmp);
		tmp[sa[0]] = 0;
		for (int i = 1; i < N; i++) {
			tmp[sa[i]] = tmp[sa[i - 1]];
			if (cmp(sa[i - 1], sa[i]))
				tmp[sa[i]]++;
		}
		for (int i = 0; i < N; i++)
			group[i] = tmp[i];
	}
}
void getLCP() {
	for (int i = 0; i < N; i++) {
		r[sa[i]] = i;
	}
	int h = 0;
	for (int i = 0; i < N; i++) {
		if (r[i]) {
			int j = sa[r[i] - 1];
			while (s[i + h] == s[j + h]) h++;
			lcp[r[i]] = h;
		}
		if (h)
			h--;
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> A >> B;
	// prevent mixing A, B suffix
	s = A + '$' + B;
	N = s.length();
	M = A.length();
	getSA();
	getLCP();
	int ans = 0;
	for (int i = 1; i < N; i++) {
		// compare same string suffix is not LCS 
		if ((sa[i - 1] - M) * (sa[i] - M) > 0)
			continue;
		if (ans < lcp[i]) {
			ans = lcp[i];
			// we compare sa[i-1], sa[i] => substr(sa[i-1], ans)
			res = s.substr(sa[i - 1], ans);
		}
	}
	cout << ans << "\n" << res << "\n";
}