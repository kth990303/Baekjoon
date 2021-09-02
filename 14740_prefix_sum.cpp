// 210902 #14740 Highway Track Gold II
// prefix_sum
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
const int MAX = 500003;
ll N, a[MAX], b[MAX], c[MAX], p[MAX];
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> b[i];
		c[i] = a[i] - b[i];
	}
	ll tmp = 1e7;
	for (int i = 1; i <= N; i++) {
		p[i] = p[i - 1] + c[i];
		tmp = min(tmp, p[i]);
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		if (tmp == p[i])
			ans++;
	}
	cout << ans << "\n";
}