// 210901 #22988 재활용 캠페인 Gold I
// two_pointers

/* only sorting corner case:
* 5 15
* 1 2 3 4 5
* ans: 2
* */
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
typedef long double ld;
const int MAX = 100001;
ld N, X;
vector<ld> v;
vector<pair<ld, ld>> res;
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> X;
	ll ans = 0;
	v.resize(N);
	for (int i = 0; i < N; i++)
		cin >> v[i];
	sort(all(v));
	int s = 0, e = N - 1;
	ll cnt = N;
	for (; e >= s; e--) {
		if (v[e] != X)
			break;
		ans++;
		cnt--;
	}
	while (s < e) {
		ll n = v[s] + v[e];
		if (n >= X / 2) {
			ans++;
			s++; e--;
			cnt -= 2;
		}
		else {
			s++;
		}
	}
	cout << ans + cnt / 3 << "\n";
}