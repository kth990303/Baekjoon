// 210516 #2613 숫자구슬 Gold II
// binary_Search
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 301;
const int INF = 0x3fffffff;
int N, M, a[MAX], ans = INF;
vector<int> res;
bool check(int n) {
	int ret = 0, p = 0, cnt = 0;
	for (int i = 0; i < N; i++) {
		if (ret + a[i] > n) {
			p++;
			cnt = 1;
			ret = a[i];
		}
		else {
			ret += a[i];
			cnt++;
		}
	}
	if (ret && ret <= n)
		p++;
	else
		p = INF;
	if (p <= M)
		return true;
	return false;
}
void solve(int s, int e) {
	while (s <= e) {
		int mid = (s + e) / 2;
		if (check(mid)) {
			ans = min(ans, mid);
			e = mid - 1;
		}
		else
			s = mid + 1;
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	int s = 0;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		s = max(s, a[i]);
	}
	solve(s, INF);
	cout << ans << "\n";
	int ret = 0, p = 0, cnt = 0;
	for (int i = 0; i < N; i++) {
		if (ret + a[i] > ans || N - i == M - p - 1) {
			cout << cnt << " ";
			cnt = 1;
			p++;
			ret = a[i];
		}
		else {
			ret += a[i];
			cnt++;
		}
	}
	cout << cnt << "\n";
}