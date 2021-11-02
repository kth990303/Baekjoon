// 210813 #1605 반복 부분문자열 Platinum III
// LCP Array O(Nlg^2(N))
// lcp's property
#include <iostream>
#include <string>
#include <algorithm>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
const int MAX = 200001;
int N, sa[MAX], lcp[MAX], group[MAX], tmp[MAX], r[MAX], t;
string s;
bool cmp(int x, int y) {
	if (group[x] == group[y]) {
		x += t;
		y += t;
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
	for (int i = 0; i < N; i++)
		r[sa[i]] = i;
	int h = 0;
	for (int i = 0; i < N; i++) {
		if (r[i]) {
			int j = sa[r[i] - 1];
			while (s[i + h] == s[j + h])
				h++;
			lcp[r[i]] = h;
		}
		if (h)
			h--;
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> s;
	getSA();
	getLCP();
	int ans = 0;
	for (int i = 1; i < N; i++) {
		ans = max(ans, lcp[i]);
	}
	cout << ans << "\n";
}