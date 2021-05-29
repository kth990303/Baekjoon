// 210529 #1561 ³îÀÌ°ø¿ø Gold II
// binary_search
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
const int MAX = 10001;
int N, M, a[MAX];
ll solve(ll s, ll e) {
	ll ans = -1;
	while (s <= e) {
		ll ret = 0;
		ll mid = (s + e) / 2;
		for (int i = 1; i <= M; i++) {
			ret += 1 + mid / a[i];
		}
		if (ret >= N) {
			ans = mid;
			e = mid - 1;
		}
		else
			s = mid + 1;
	}
	return ans;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	if (N <= M) {
		cout << N << "\n";
		return 0;
	}
	for (int i = 1; i <= M; i++) {
		cin >> a[i];
	}
	ll s = 0, e = 1e11;
	ll time = solve(s, e);
	ll k = 0;
	for (int i = 1; i <= M; i++) {
		k += 1 + (time - 1) / a[i];
	}
	for (int i = 1; i <= M; i++) {
		if (!(time % a[i]))
			k++;
		if (k == N) {
			cout << i << "\n";
			return 0;
		}
	}
}