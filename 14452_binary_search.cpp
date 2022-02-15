// 220216 #14452 Cow Dance Show Gold III
// binary_search, priority_queue
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
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
const int MAX = 1e6 + 11;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e16;
const int MOD = 1e9 + 7;
int N, T, a[MAX];
int solve(int s, int e) {
	int ans = e;
	while (s <= e) {
		int mid = (s + e) / 2;
		int ret = 0;
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 0; i < mid; i++) {
			ret = max(ret, a[i]);
			pq.push(a[i]);
		}
		for (int i = mid; i < N; i++) {
			int n = pq.top();
			pq.pop();
			pq.push(n + a[i]);
			ret = max(ret, n + a[i]);
		}
		if (ret <= T) {
			ans = mid;
			e = mid - 1;
		}
		else
			s = mid + 1;
	}
	return ans;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> T;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	cout << solve(1, N);
}