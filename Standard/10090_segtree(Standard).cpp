// 210116 #10090 Counting Inversions Gold I
// DS_segtree (Standard)
#include <iostream>
using namespace std;
typedef long long ll;
const int MAX = 1000001;
ll N, a[MAX], tree[1 << 21], ans;
int query(int node, int s, int e, int left, int right) {
	if (e < left || right < s)
		return 0;
	if (left <= s && e <= right)
		return tree[node];
	int mid = (s + e) / 2;
	return query(node * 2, s, mid, left, right)
		+ query(node * 2 + 1, mid + 1, e, left, right);
}
void update(int node, int s, int e, int idx, int val) {
	if (e < idx || idx < s)
		return;
	tree[node] += val;
	if (s != e) {
		int mid = (s + e) / 2;
		update(node * 2, s, mid, idx, val);
		update(node * 2 + 1, mid + 1, e, idx, val);
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		ans += query(1, 1, N, a[i] + 1, N);
		update(1, 1, N, a[i], 1);
	}
	cout << ans << "\n";
}