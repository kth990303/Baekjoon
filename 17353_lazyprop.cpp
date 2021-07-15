// 210715 #17353 하늘에서 떨어지는 1,2,...,R-L+1개의 별 Platinum II
// lazyprop + prefix_sum
#include <iostream>
#include <algorithm>
#include <vector>
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const int MAX = 100001;
const int INF = 0x3f3f3f3f; 
struct Tree {
	ll val, lazy;
};
int N, Q;
ll a[MAX], tmp[MAX];
Tree tree[1 << 18];
ll init(int node, int s, int e) {
	if (s == e)
		return tree[node].val = a[s];
	int mid = (s + e) / 2;
	return tree[node].val = init(node * 2, s, mid)
		+ init(node * 2 + 1, mid + 1, e);
}
void update_lazy(int node, int s, int e) {
	if (tree[node].lazy) {
		tree[node].val += ((ll)e - s + 1) * tree[node].lazy;
		if (s != e) {
			tree[node * 2].lazy += tree[node].lazy;
			tree[node * 2 + 1].lazy += tree[node].lazy;
		}
		tree[node].lazy = 0;
	}
}
ll query(int node, int s, int e, int left, int right) {
	update_lazy(node, s, e);
	if (e < left || right < s)
		return 0;
	if (left <= s && e <= right)
		return tree[node].val;
	int mid = (s + e) / 2;
	return query(node * 2, s, mid, left, right)
		+ query(node * 2 + 1, mid + 1, e, left, right);
}
void update(int node, int s, int e, int left, int right, ll diff) {
	update_lazy(node, s, e);
	if (e < left || right < s)
		return;
	if (left <= s && e <= right) {
		tree[node].lazy += diff;
		update_lazy(node, s, e);
		return;
	}
	int mid = (s + e) / 2;
	update(node * 2, s, mid, left, right, diff);
	update(node * 2 + 1, mid + 1, e, left, right, diff);
	tree[node].val = tree[node * 2].val + tree[node * 2 + 1].val;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> tmp[i];
	}
	for (int i = 0; i < N; i++) {
		a[i] = tmp[i];
		// a[i]: tmp[i]-tmp[i-1]
		// d(a[i]): AP sequence
		if (i)
			a[i] -= tmp[i - 1];
	}
	init(1, 0, N - 1);
	cin >> Q;
	while (Q--) {
		int ch, s, e;
		cin >> ch;
		if (ch == 1) {
			cin >> s >> e;
			--s; --e;
			update(1, 0, N - 1, s, e, 1);
			update(1, 0, N - 1, e + 1, e + 1, -((ll)e - s + 1));
		}
		else {
			cin >> s;
			--s;
			cout << query(1, 0, N - 1, 0, s) << "\n";
		}
	}
}