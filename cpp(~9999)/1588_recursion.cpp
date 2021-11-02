// 210810 #1588 ¼ö¿­ Gold I
// recursion, impl
#include <iostream>
#include <algorithm>
#include <cmath>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
ll N, L, R, T, num[4] = { 0,132,211,232 };
int ans1, ans2, ans3;
int d[4][4] = {
	{0,0,0,0},
	{0,0,1,1},
	{0,2,0,0},
	{0,0,2,0}
};
void calc(int n1, int n2, int n3, int t) {
	if (!t) {
		ans1 += n1;
		ans2 += n2;
		ans3 += n3;
		return;
	}
	int cnt1 = n1 + n1 * d[1][1] + n2 * d[2][1] + n3 * d[3][1];
	int cnt2 = n2 + n1 * d[1][2] + n2 * d[2][2] + n3 * d[3][2];
	int cnt3 = n3 + n1 * d[1][3] + n2 * d[2][3] + n3 * d[3][3];
	calc(cnt1, cnt2, cnt3, t - 1);
}
void check(int n, int t) {
	if (n == 1)
		calc(1, 0, 0, t);
	else if (n == 2)
		calc(0, 1, 0, t);
	else
		calc(0, 0, 1, t);
}
void solve(int n, ll t, ll l) {
	if (!t) {
		if (l >= L && l <= R)
			check(n / 100, t);
		if (l + 1 >= L && l + 1 <= R)
			check((n % 100) / 10, t);
		if (l + 2 >= L && l + 2 <= R)
			check(n % 10, t);
		return;
	}
	ll idx1 = l;
	ll idx2 = l + pow(3, t);
	ll idx3 = l + 2 * pow(3, t);
	ll idx4 = l + 3 * pow(3, t);
	if (idx4 < L || idx1>R)
		return;

	if (idx1 >= L && idx2 - 1 <= R)
		check(n / 100, t);
	else if (idx1 <= R || idx2 - 1 >= L)
		solve(num[n / 100], t - 1, idx1);
	else
		return;

	if (idx2 >= L && idx3 - 1 <= R)
		check((n % 100) / 10, t);
	else if (idx2 <= R || idx3 - 1 >= L)
		solve(num[(n % 100) / 10], t - 1, idx2);
	else
		return;

	if (idx3 >= L && idx4 - 1 <= R)
		check(n % 10, t);
	else if (idx3 <= R || idx4 - 1 >= L)
		solve(num[n % 10], t - 1, idx3);
	else
		return;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> L >> R >> T;
	if (!T)
		check(N, 0);
	else
		solve(num[N], T - 1, 0);
	cout << ans1 << " " << ans2 << " " << ans3 << "\n";
}