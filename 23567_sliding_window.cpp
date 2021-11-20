// 211120 #23567 Double Rainbow Gold V
// icpc 2021 seoul regional
// sliding_window + binary_search
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 10011;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e16;
const int MOD = 1e9 + 7;
int N, K, a[MAX];
bool solve(int k) {
	map<int, int> m, m2;
	for (int i = 1; i <= N; i++) {
		m2[a[i]]++;
	}
	for (int i = 1; i <= k; i++) {
		m[a[i]]++;
		if (--m2[a[i]] == 0)m2.erase(a[i]);
		if (m.size() == K && m2.size() == K)
			return true;
	}
	for (int i = 1; i + k <= N; i++) {
		m[a[i]]--;
		m2[a[i]]++;
		if (!m[a[i]]) m.erase(a[i]);
		m[a[i + k]]++;
		m2[a[i + k]]--;
		if (!m2[a[i+k]])m2.erase(a[i+k]);
		if (m.size() == K && m2.size() == K)
			return true;
	}
	return false;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> K;
	for (int i = 1; i <= N; i++)
		cin >> a[i];
	int s = 1, e = N, ans = 0;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (solve(mid)) {
			ans = mid;
			e = mid - 1;
		}
		else
			s = mid + 1;
	}
	cout << ans << "\n";
}