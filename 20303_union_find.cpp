// 211125 #20303 할로윈의 양아치 Gold III
// union_find, knapsack_dp
// O(NK)
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
typedef pair<ll, pl> pll;
const int MAX = 30011;
const int INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N, M, K, candy[MAX], cnt[MAX], p[MAX], d[3001];
vector<pi> v;
bool vis[MAX];
int find(int a) {
	if (a == p[a])
		return a;
	return p[a] = find(p[a]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return false;
	if (a > b)swap(a, b);
	p[b] = a;
	candy[a] += candy[b];
	return true;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		p[i] = i;
		cin >> candy[i];
	}
	while(M--) {
		int a, b;
		cin >> a >> b;
		merge(a, b);
	}
	for (int i = 1; i <= N; i++) {
		cnt[find(i)]++;
	}
	for (int i = 1; i <= N; i++) {
		if (vis[find(i)])
			continue;
		vis[find(i)] = true;
		v.push_back({ cnt[find(i)], candy[find(i)] });
	}
	for (int i = 0; i < v.size(); i++) {
		for (int j = K; j >= v[i].first; j--) {
			d[j] = max(d[j], d[j - v[i].first] + v[i].second);
		}
	}
	int ans = 0;
	for (int i = 0; i < K; i++) {
		ans = max(ans, d[i]);
	}
	cout << ans << "\n";
}