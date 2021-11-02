// 210810 #9248 Suffix Array Platinum III
// suffix array && lcp (Standard)
// O(Nlg^2N)
#include <iostream>
#include <vector>
#include <algorithm>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
const int MAX = 500001;
string s;
int N, t, sa[MAX], lcp[MAX], group[MAX], tmp[MAX], r[MAX];
bool cmp(int x, int y) {
	if (group[x] == group[y]) {
		x += t; y += t;
		if(x<N && y<N)
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

	cin >> s;
	N = s.length();
	getSA();
	for (int i = 0; i < N; i++) {
		cout << 1 + sa[i] << " ";
	}
	cout << "\nx ";
	getLCP();
	for (int i = 1; i < N; i++) {
		cout << lcp[i] << " ";
	}
	cout << "\n";
}