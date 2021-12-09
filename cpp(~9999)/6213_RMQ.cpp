// 211209 #6213 Balanced Lineup Gold I
// RMQ Standard O(QlgN)
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
const int MAX = 50011;
const int INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N, Q, a[MAX], tree[1 << 17], mtree[1 << 17];
int init(int node, int s, int e) {
	if (s == e)return tree[node] = a[s];
	int mid = (s + e) / 2;
	return tree[node] = max(init(node * 2, s, mid),
		init(node * 2 + 1, mid + 1, e));
}
int minit(int node, int s, int e) {
	if (s == e)return mtree[node] = a[s];
	int mid = (s + e) / 2;
	return mtree[node] = min(minit(node * 2, s, mid),
		minit(node * 2 + 1, mid + 1, e));
}
int query(int node, int s, int e, int left, int right) {
	if (e < left || right < s)
		return -INF;
	if (left <= s && e <= right)
		return tree[node];
	int mid = (s + e) / 2;
	return max(query(node * 2, s, mid, left, right)
		,query(node * 2 + 1, mid + 1, e, left, right));
}
int mquery(int node, int s, int e, int left, int right) {
	if (e < left || right < s)
		return INF;
	if (left <= s && e <= right)
		return mtree[node];
	int mid = (s + e) / 2;
	return min(mquery(node * 2, s, mid, left, right)
		, mquery(node * 2 + 1, mid + 1, e, left, right));
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	init(1, 1, N);
	minit(1, 1, N);
	while (Q--) {
		int s, e;
		cin >> s >> e;
		cout << query(1, 1, N, s, e) - mquery(1, 1, N, s, e) << "\n";
	}
}