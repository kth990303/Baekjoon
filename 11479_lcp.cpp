// 211214 #11479 서로 다른 부분 문자열의 개수 2 Platinum II
// lcp
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MAX = 1000011;
const int INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
string s;
int N, sa[MAX], group[MAX], t, lcp[MAX], tmp[MAX], r[MAX];
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
			while (s[i + h] == s[j + h])h++;
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
	getLCP();
	// if lcp, duplicate substring
	ll ans = 1LL * N * (1LL * N + 1) / 2;
	for (int i = 0; i < N; i++) {
		ans -= 1LL * lcp[i];
	}
	cout << ans;
}