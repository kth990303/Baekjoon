// 200904 #18436 수열과쿼리 37 Platinum V
// 전형적인 segtree
// 2주 전엔 이것도 못풀었었는데 세그트리 구조 익히면서 실력이 늘은듯
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int MAX = 100001;
int N, M, a[MAX];
// 홀수의 개수
int init(vector<int>& tree, int node, int s, int e) {
	if (s == e)
		return tree[node] = a[s] % 2;
	int mid = (s + e) / 2;
	return tree[node] = init(tree, node * 2, s, mid)
		+ init(tree, node * 2 + 1, mid + 1, e);
}
// 홀수 개수 반환
int query(vector<int>& tree, int node, int s, int e, int left, int right) {
	if (e < left || right < s)
		return 0;
	if (left <= s && e <= right)
		return tree[node];
	int mid = (s + e) / 2;
	return query(tree, node * 2, s, mid, left, right)
		+ query(tree, node * 2 + 1, mid + 1, e, left, right);
}
void update(vector<int>& tree, int node, int s, int e, int idx, int val) {
	if (e < idx || idx < s)
		return;
	if (s == e) {
		if (s == idx) {
			tree[node] = val % 2;
			return;
		}
	}
	int mid = (s + e) / 2;
	update(tree, node * 2, s, mid, idx, val);
	update(tree, node * 2 + 1, mid + 1, e, idx, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	int size = ceil(log2(MAX));
	int tree_size = 4 + (1 << (size + 1));

	vector<int> tree(tree_size);
	init(tree, 1, 1, N);
	cin >> M;
	while (M--) {
		int ch, b, c;
		cin >> ch >> b >> c;
		// update
		if (ch == 1) {
			a[b] = c;
			update(tree, 1, 1, N, b, c);
		}
		// query1: 짝수 개수 출력
		else if (ch == 2) {
			if (c < b)
				swap(c, b);
			int num = abs(c - b + 1);
			cout << num - query(tree, 1, 1, N, b, c) << "\n";
		}
		// query2: 홀수 개수 출력
		else {
			if (c < b)
				swap(c, b);
			cout << query(tree, 1, 1, N, b, c) << "\n";
		}
	}
}