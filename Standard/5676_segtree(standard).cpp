// 200906 #5676 음주코딩 Platinum V
// 전형적인 segtree.
#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;
const int MAX = 100001;
int a[MAX], N, K;
int init(vector<int>& tree, int node, int s, int e) {
	if (s == e)
		return tree[node] = a[s];
	int mid = (s + e) / 2;
	return tree[node] = init(tree, node * 2, s, mid)
		* init(tree, node * 2 + 1, mid + 1, e);
}
int query(vector<int>& tree, int node, int s, int e, int left, int right) {
	if (e < left || right < s)
		return 1;
	if (left <= s && e <= right) {
		return tree[node];
	}
	int mid = (s + e) / 2;
	return query(tree, node * 2, s, mid, left, right)
		* query(tree, node * 2 + 1, mid + 1, e, left, right);
}
void update(vector<int>& tree, int node, int s, int e, int idx, int val) {
	if (e < idx || idx < s)
		return;
	if (s == e) {
		if (s == idx) {
			tree[node] = val;
			return;
		}
	}
	int mid = (s + e) / 2;
	update(tree, node * 2, s, mid, idx, val);
	update(tree, node * 2 + 1, mid + 1, e, idx, val);
	tree[node] = tree[node * 2] * tree[node * 2 + 1];
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	while (cin >> N >> K) {
		fill(a, a + MAX, 0);
		int size = ceil(log2(N) + 1);
		int tree_size = 1 << size;
		vector<int> tree(tree_size);

		for (int i = 1; i <= N; i++) {
			int num;
			cin >> num;
			if (num > 0)
				a[i] = 1;
			else if (num < 0)
				a[i] = -1;
			else
				a[i] = 0;
		}
		init(tree, 1, 1, N);
		for (int i = 0; i < K; i++) {
			char ch;
			int b, c;
			cin >> ch >> b >> c;
			// update
			if (ch == 'C') {
				if (c > 0)
					c = 1;
				else if (c < 0)
					c = -1;
				else
					c = 0;
				a[b] = c;
				update(tree, 1, 1, N, b, c);
			}
			// query
			else {
				int ans = query(tree, 1, 1, N, b, c);
				if (ans > 0)
					cout << "+";
				else if (ans < 0)
					cout << "-";
				else
					cout << "0";
			}
		}
		cout << "\n";
	}
}