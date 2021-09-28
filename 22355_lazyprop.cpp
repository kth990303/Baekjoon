// 210928 #22355 ¸»¶Ò Platinum II
// I think it's Platinum I
// lazy_prop + ternary_search O(Nlg^2H), but recursion segtree is slow
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
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
const int MAX = 100011;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
struct Tree {
	ll val, lazy;
};
ll N, K, a[MAX], asc[MAX], desc[MAX], ans = LNF;
vector<Tree> tree, cons;
void update_lazy(vector<Tree>&tree, int node, int s, int e) {
	if (tree[node].lazy) {
		tree[node].val += ((ll)e - s + 1) * tree[node].lazy;
		if (s != e) {
			tree[node * 2].lazy += tree[node].lazy;
			tree[node * 2 + 1].lazy += tree[node].lazy;
		}
		tree[node].lazy = 0;
	}
}
ll query(vector<Tree>& tree, int node, int s, int e, int left, int right) {
	update_lazy(tree, node, s, e);
	if (e < left || right < s)
		return 0;
	if (left <= s && e <= right)
		return tree[node].val;
	int mid = (s + e) / 2;
	return query(tree, node * 2, s, mid, left, right)
		+ query(tree, node * 2 + 1, mid + 1, e, left, right);
}
void update(vector<Tree>& tree, int node, int s, int e, 
	int left, int right, ll diff) {
	update_lazy(tree, node, s, e);
	if (e < left || right < s)
		return;
	if (left <= s && e <= right) {
		tree[node].lazy += diff;
		update_lazy(tree, node, s, e);
		return;
	}
	int mid = (s + e) / 2;
	update(tree, node * 2, s, mid, left, right, diff);
	update(tree, node * 2 + 1, mid + 1, e, left, right, diff);
	tree[node].val = tree[node * 2].val + tree[node * 2 + 1].val;
}
ll solve(int s, int e) {
	while (s + 3 <= e) {
		int p = (s * 2 + e) / 3;
		int q = (s + e * 2) / 3;
		ll A1 = query(tree, 1, 1, MAX, p, p);
		ll A2 = query(tree, 1, 1, MAX, q, q);
		ll B1 = query(cons, 1, 1, MAX, p, p);
		ll B2 = query(cons, 1, 1, MAX, q, q);
		if (A1 * p + B1 > 
			A2 * q + B2)
			s = p;
		else
			e = q;
	}
	ll ret = LNF;
	for (int i = s; i <= e; i++) {
		ll A = query(tree, 1, 1, MAX, i, i);
		ll B = query(cons, 1, 1, MAX, i, i);
		ret = min(ret, A * i + B);
	}
	return ret;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> K;
	tree.resize(1 << 18);
	cons.resize(1 << 18);
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> asc[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> desc[i];
	}
	for (int i = 1; i <= N; i++) {
		update(tree, 1, 1, MAX, 1, a[i]-1, -desc[i]);
		update(cons, 1, 1, MAX, 1, a[i]-1, desc[i] * a[i]);
		update(tree, 1, 1, MAX, a[i], MAX, asc[i]);
		update(cons, 1, 1, MAX, a[i], MAX, -asc[i] * a[i]);
		if (i >= K) {
			ans = min(ans, solve(1, 100000));
			update(tree, 1, 1, MAX, 1, a[i-K+1] - 1, desc[i-K+1]);
			update(cons, 1, 1, MAX, 1, a[i-K+1] - 1, -desc[i-K+1] * a[i - K+1]);
			update(tree, 1, 1, MAX, a[i-K+1], MAX, -asc[i-K+1]);
			update(cons, 1, 1, MAX, a[i-K+1], MAX, asc[i-K+1] * a[i-K+1]);
		}
	}
	cout << ans << "\n";
}