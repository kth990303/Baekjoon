// 211004 #13925 ¼ö¿­°úÄõ¸®13 Diamond V
// Range multiply + Range Plus
// two lazy Arrays
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
const ll MOD = 1e9 + 7;
ll N, M, a[MAX];
struct Tree {
	ll val, lazy[2] = {1, 0};
};
Tree tree[1 << 18];
void update_lazy(int node, int s, int e) {
	if (tree[node].lazy[0]!=1) {
		tree[node].val *= tree[node].lazy[0];
		tree[node].val %= MOD;
		if (s != e) {
			ll k = tree[node].lazy[0];
			tree[node * 2].lazy[0] *= k;
			tree[node * 2].lazy[1] *= k;
			tree[node * 2].lazy[0] %= MOD; tree[node * 2].lazy[1] %= MOD;
			tree[node * 2 + 1].lazy[0] *= k;
			tree[node * 2 + 1].lazy[1] *= k;
			tree[node * 2 + 1].lazy[0] %= MOD; tree[node * 2 + 1].lazy[1] %= MOD;
		}
		tree[node].lazy[0] = 1;
	}
	if (tree[node].lazy[1]) {
		tree[node].val += (1LL * e - s + 1) * tree[node].lazy[1];
		tree[node].val %= MOD;
		if (s != e) {
			ll k = tree[node].lazy[1];
			tree[node * 2].lazy[1] += k;
			tree[node * 2].lazy[1] %= MOD;
			tree[node * 2 + 1].lazy[1] += k;
			tree[node * 2 + 1].lazy[1] %= MOD;
		}
		tree[node].lazy[1] = 0;
	}
}
ll init(int node, int s, int e) {
	if (s == e)
		return tree[node].val = a[s];
	int mid = (s + e) / 2;
	return tree[node].val = (init(node * 2, s, mid)
		+ init(node * 2 + 1, mid + 1, e)) % MOD;
}
ll query(int node, int s, int e, int left, int right) {
	update_lazy(node, s, e);
	if (e < left || right < s)
		return 0;
	if (left <= s && e <= right)
		return tree[node].val % MOD;
	int mid = (s + e) / 2;
	return (query(node * 2, s, mid, left, right)
		+ query(node * 2 + 1, mid + 1, e, left, right)) % MOD;
}
void update_plus(int node, int s, int e, int left, int right, ll diff) {
	update_lazy(node, s, e);
	if (e < left || right < s)
		return;
	if (left <= s && e <= right) {
		tree[node].lazy[0] = 1;
		tree[node].lazy[1] += diff;
		tree[node].lazy[1] %= MOD;
		update_lazy(node, s, e);
		return;
	}
	int mid = (s + e) / 2;
	update_plus(node * 2, s, mid, left, right, diff);
	update_plus(node * 2 + 1, mid + 1, e, left, right, diff);
	tree[node].val = (tree[node * 2].val + tree[node * 2 + 1].val) % MOD;
}
void update_multi(int node, int s, int e, int left, int right, ll diff) {
	update_lazy(node, s, e);
	if (e < left || right < s)
		return;
	if (left <= s && e <= right) {
		tree[node].lazy[0] = diff;
		tree[node].lazy[1] = 0;
		update_lazy(node, s, e);
		return;
	}
	int mid = (s + e) / 2;
	update_multi(node * 2, s, mid, left, right, diff);
	update_multi(node * 2 + 1, mid + 1, e, left, right, diff);
	tree[node].val = (tree[node * 2].val + tree[node * 2 + 1].val) % MOD;
}
void update(int node, int s, int e, int left, int right, ll val) {
	update_lazy(node, s, e);
	if (e < left || right < s)
		return;
	if (left <= s && e <= right) {
		tree[node].lazy[0] = 0;
		tree[node].lazy[1] = val;
		update_lazy(node, s, e);
		return;
	}
	int mid = (s + e) / 2;
	update(node * 2, s, mid, left, right, val);
	update(node * 2 + 1, mid + 1, e, left, right, val);
	tree[node].val = (tree[node * 2].val + tree[node * 2 + 1].val) % MOD;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	init(1, 1, N);
	cin >> M;
	while (M--) {
		int ch, x, y;
		ll v;
		cin >> ch >> x >> y;
		if (ch == 1) {
			cin >> v;
			update_plus(1, 1, N, x, y, v);
		}
		else if (ch == 2) {
			cin >> v;
			update_multi(1, 1, N, x, y, v);
		}
		else if (ch == 3) {
			cin >> v;
			update(1, 1, N, x, y, v);
		}
		else {
			cout << query(1, 1, N, x, y) % MOD << "\n";
		}
	}
}