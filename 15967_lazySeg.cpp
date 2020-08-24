// 200824 #15967 에바쿰 Platinum IV
// 전형적인 Lazy propagation of Segtree
// query가 range로 주어지고, 범위가 무려 10만...
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
ll a[1000001];
typedef struct tree {
	ll value, lazy;
} Tree;
Tree tree[4000004];	
int N, P, Q;
ll init(int node, int s, int e) {
	if (s == e)
		return tree[node].value = a[s];
	int mid = (s + e) / 2;
	return tree[node].value = init(node * 2, s, mid) 
		+ init(node * 2 + 1, mid + 1, e);
}
ll query(int node, int s, int e, int left, int right) {
	if (tree[node].lazy != 0) {
		tree[node].value += ((ll)e - (ll)s + 1) * tree[node].lazy;
		if (s != e) {
			tree[node * 2].lazy += tree[node].lazy;
			tree[node * 2 + 1].lazy += tree[node].lazy;
		}
		tree[node].lazy = 0;
	}
	if (e < left || right < s)
		return 0;
	if (left <= s && e <= right)
		return tree[node].value;
	int mid = (s + e) / 2;
	return query(node * 2, s, mid, left, right)
		+ query(node * 2 + 1, mid + 1, e, left, right);
}
void update(int node, int s, int e, int left, int right, ll diff) {
	if (tree[node].lazy != 0) {
		tree[node].value += ((ll)e - (ll)s + 1) * tree[node].lazy;
		if (s != e) {
			tree[node * 2].lazy += tree[node].lazy;
			tree[node * 2 + 1].lazy += tree[node].lazy;
		}
		tree[node].lazy = 0;
	}
	if (e < left || right < s)
		return;
	if (left <= s && e <= right) {
		tree[node].value += ((ll)e - (ll)s + 1) * diff;
		if (s != e) {
			tree[node * 2].lazy += diff;
			tree[node * 2 + 1].lazy += diff;
		}
		return;
	}
	int mid = (s + e) / 2;
	update(node * 2, s, mid, left, right, diff);
	update(node * 2 + 1, mid + 1, e, left, right, diff);
	tree[node].value = tree[node * 2].value + tree[node * 2 + 1].value;
}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> P >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	init(1, 1, N);
	for (int i = 0; i < P + Q; i++) {
		int ch;
		cin >> ch;
		// query
		if (ch == 1) {
			int b, c;
			cin >> b >> c;
			cout << query(1, 1, N, b, c) << "\n";
		}
		// update
		else {
			int b, c;
			ll diff;
			cin >> b >> c >> diff;
			update(1, 1, N, b, c, diff);
		}
	}
}