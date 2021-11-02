// 211020 #2300 ±âÁö±¹ Gold III
// dp O(N^2)
// choice can influence others
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
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
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
int N, ans, d[MAX];
vector<pi> v;
int dp(int cur) {
	if (cur >= N)
		return 0;
	int& ret = d[cur];
	if (ret != -1)
		return ret;
	ret = INF;
	int garo = 0, sero = 0;
	for (int i = cur; i < N; i++) {
		garo = v[i].first - v[cur].first;
		sero = max(sero, 2 * abs(v[i].second));
		int n = max(garo, sero);
		ret = min(ret, dp(i + 1) + n);
	}
	return ret;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		v.push_back({ x,y });
	}
	sort(all(v));
	memset(d, -1, sizeof(d));
	cout << dp(0) << "\n";
}