// 210606 #1477 휴게소 세우기 Gold IV
// greedy? No, binary_search
// ganeung? ganeung? SsibGaneung mode
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
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 101;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
int N, M, L, ans;
vector<int> v;
int solve(int s, int e) {
	while (s <= e) {
		int mid = (s + e) / 2;
		int ret = (v[0] - 1) / mid;
		for (int i = 1; i < N; i++) {
			ret += (v[i] - v[i - 1] - 1) / mid;
		}
		ret += (L - v[N - 1] - 1) / mid;
		if (ret <= M) {
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

	cin >> N >> M >> L;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(all(v));
	int s = 0, e = L;
	cout << solve(s, e) << "\n";
}