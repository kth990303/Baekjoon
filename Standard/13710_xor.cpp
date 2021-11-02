#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 100011;
int N;
ll cnt[30][2], a[MAX], p[MAX];
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		p[i] = p[i - 1] ^ a[i];
	}
	for (int i = 0; i <= N; i++) {
		for (int j = 0; j < 30; j++) {
			cnt[j][(bool)(p[i] & (1 << j))]++;
		}
	}
	ll ans = 0;
	for (int i = 0; i < 30; i++) {
		ans += cnt[i][0] * cnt[i][1] * (1LL << i);
	}
	cout << ans << "\n";
}