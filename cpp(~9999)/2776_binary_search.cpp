// 210102 #2776 ¾Ï±â¿Õ Silver III
// Binary_search (Standard + 0.5 level)
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 1000001;
ll N, M, a[MAX], b[MAX];
bool solve(ll num) {
	ll s = 0, e = N - 1;
	while (s <= e) {
		ll mid = (s + e) / 2;
		// if same number, finish the function
		if (a[mid] == num)
			return true;
		// else, change the s or e
		// if there isn't same number, in the end, s>e
		if (a[mid] < num) {
			s = mid + 1;
		}
		else
			e = mid - 1;
	}
	return false;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> a[i];
		}
		sort(a, a + N);
		cin >> M;
		for (int i = 0; i < M; i++) {
			cin >> b[i];
			// standard solution: 652ms 17640KB
			cout << solve((ll)b[i]) << "\n";
			// easy solution: binary_search(a, a+N, b[i]); : 624ms 9828KB
		}
	}
}