// 210823 #17408 수열과쿼리24 Platinum III
// pi.first=max, pi.second=second max
// double_maximum_segtree(Standard) O(MlgN)
// another sol. {index, value}
#include <iostream>
#include <algorithm>
#include <vector>
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
const int MAX = 100001;
int N, M, a[MAX];
pi tree[1 << 18];
pi merge(pi p1, pi p2) {
	if (p1.first < p2.first)
		swap(p1, p2);
	return { p1.first, max(p1.second, p2.first) };
}
pi query(int node, int s, int e, int left, int right) {
	if (e < left || right < s)
		return { 0, 0 };
	if (left <= s && e <= right)
		return tree[node];
	int mid = (s + e) / 2;
	return merge(query(node * 2, s, mid, left, right)
		,query(node * 2 + 1, mid + 1, e, left, right));
}
void update(int node, int s, int e, int idx, int val) {
	if (e < idx || idx < s)
		return;
	tree[node] = { val, 0 };
	if (s != e) {
		int mid = (s + e) / 2;
		update(node * 2, s, mid, idx, val);
		update(node * 2 + 1, mid + 1, e, idx, val);
		tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		update(1, 1, N, i, a[i]);
	}
	cin >> M;
	while (M--) {
		int ch;
		cin >> ch;
		if (ch == 1) {
			int i, v;
			cin >> i >> v;
			update(1, 1, N, i, v);
		}
		else {
			int l, r;
			cin >> l >> r;
			pi ans = query(1, 1, N, l, r);
			cout << ans.first + ans.second << "\n";
		}
	}
}