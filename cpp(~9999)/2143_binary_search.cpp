// 210919 #2143 두 배열의 합 Gold III
// prefix_sum + binary_search
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MAX = 1001;
const int MOD = 1e9 + 7;
ll T, N, M, a[MAX], b[MAX], p1[MAX], p2[MAX];
vector<ll> v1, v2;
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> T >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		p1[i] = p1[i - 1] + a[i];
	}
	cin >> M;
	for (int i = 1; i <= M; i++) {
		cin >> b[i];
		p2[i] = p2[i - 1] + b[i];
	}
	for (int i = 1; i <= N; i++) {
		for (int j = i; j <= N; j++) {
			v1.push_back(p1[j] - p1[i - 1]);
		}
	}
	for (int i = 1; i <= M; i++) {
		for (int j = i; j <= M; j++) {
			v2.push_back(p2[j] - p2[i - 1]);
		}
	}
	sort(all(v1));
	sort(all(v2));
	ll ans = 0;
	for (int i = 0; i < v1.size(); i++) {
		ll num = T - v1[i];
		if (binary_search(all(v2), num))
			ans += 1LL*(upper_bound(all(v2), num) - lower_bound(all(v2), num));
	}
	cout << ans << "\n";
}