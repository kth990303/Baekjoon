// 210511 #3015 오아시스 재결합 Gold I
// use Stack
// like #6549
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long ll;
const int MAX = 500001;
const int INF = 0x3fffffff;
ll N, ans;	// long long...
stack<pair<ll, ll>> st;	// people cnt, height
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		ll n, cnt = 1;
		cin >> n;
		while (!st.empty() && st.top().second <= n) {
			ans += st.top().first;
			if (st.top().second == n) {
				cnt = st.top().first + 1;
				st.pop();
			}
			else {
				st.pop();
			}
		}
		if (!st.empty())
			ans++;
		st.push({ cnt, n });
	}
	cout << ans << "\n";
}