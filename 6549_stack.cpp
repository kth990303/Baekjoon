// 210406 #6549 히스토그램에서 가장 큰 직사각형 Platinum V
// use stack O(N)
#include <iostream>
#include <algorithm>
#include <stack>
using namespace std;
typedef long long ll;
const int MAX = 100001;
ll N, a[MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	while (cin >> N) {
		if (!N) break;
		for (int i = 0; i < N; i++) {
			cin >> a[i];
		}
		a[N] = 0;
		stack<ll> s;
		ll ans = 0, h = -1;
		for (int i = 0; i <= N; i++) {
			while (!s.empty() && a[s.top()] > a[i]) {
				h = a[s.top()];
				s.pop();
				if (s.empty())
					ans = max(ans, h * i);
				else
					ans = max(ans, h * (i - s.top() - 1));
			}
			s.push(i);
		}
		cout << ans << "\n";
	}
}