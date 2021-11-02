// 210314 #8986 Àüº¿´ë Platinum V
// ternary search (Standard)
// unimodal function: convex and only one extreme point
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const ll INF = 1e18;
const int MAX = 100001;
ll N, a[MAX], ans = INF;
ll solve(int n) {
	ll ret = 0;
	for (int i = 1; i < N; i++) {
		ret += abs(1LL * n * i - a[i]);
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	ll s = 0, e = a[N - 1];
	while (s + 3 <= e) {
		ll p = (s * 2 + e) / 3, q = (s + e * 2) / 3;
		if (solve(p) > solve(q))
			s = p;
		else
			e = q;
	}
	for (int i = s; i <= e; i ++) {
		ans = min(ans, solve(i));
	}
	cout << ans << "\n";
}