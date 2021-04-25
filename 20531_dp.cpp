// 210425 #20531 인간관계 Platinum V
// dp[i][j]: people cnt: i , group cnt: j -> division
// bell number (dp)
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAX = 5011;
const ll MOD = 1e9 + 7;
ll N, M, p[MAX], d[MAX][MAX], cnt;
int find(int a) {
	if (a == p[a])
		return a;
	return p[a] = find(p[a]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return false;
	if (a > b)
		swap(a, b);
	p[b] = a;
	cnt--;
	return true;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i <= N; i++) {
		p[i] = i;
	}
	for (int i = 1; i <= N; i++) {
		d[i][1] = d[i][i] = 1;
	}
	for (int i = 2; i <= N; i++) {
		for (int j = 2; j < i; j++) {
			d[i][j] = d[i - 1][j - 1] + d[i - 1][j] * j;
			d[i][j] %= MOD;
		}
	}
	cnt = N;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		merge(a, b);
		ll ans = 0;
		for (int j = 1; j <= cnt; j++) {
			ans += d[cnt][j];
		}
		cout << ans % MOD << "\n";
	}
	
}