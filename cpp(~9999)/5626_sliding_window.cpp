// 210813 #5626 Á¦´Ü Platinum IV
// Sliding Window (cause we can't solve O(3NH))
#include <iostream>
#include <algorithm>
#include <cstring>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
const int MAX = 10001;
const ll MOD = 1e9 + 7;
int N, a[MAX];
ll d[2][MAX];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	//freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < N; i++) {
		if (a[i] > min(i, N - i - 1)) {
			cout << 0 << "\n";
			return 0;
		}
	}
	d[0][0] = 1; d[1][0] = 1;
	for (int i = 0; i < N; i++) {
		int cur = i % 2;
		int prev = (i + 1) % 2;
		for (int j = 0; j < MAX; j++)
			d[cur][j] = 0;
		if (a[i] == -1) {
			for (int j = 0; j <= min(i, N - i - 1); j++) {
				if (j)
					d[cur][j] += d[prev][j - 1];
				d[cur][j] %= MOD;
				d[cur][j] += d[prev][j];
				d[cur][j] %= MOD;
				d[cur][j] += d[prev][j + 1];
				d[cur][j] %= MOD;
			}
		}
		else {
			d[cur][a[i]] += d[prev][a[i] + 1];
			d[cur][a[i]] %= MOD;
			d[cur][a[i]] += d[prev][a[i]];
			d[cur][a[i]] %= MOD;
			if (a[i])
				d[cur][a[i]] += d[prev][a[i] - 1];
			d[cur][a[i]] %= MOD;
		}
		if (i == N - 1)
			cout << d[cur][0] % MOD << "\n";
	}
}