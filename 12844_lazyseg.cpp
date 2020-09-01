#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
const int MAX = 500000;
int N, M, a[MAX];
void update_lazy(vector<int>& tree, vector<int>& lazy, 
	int node, int s, int e) {
	if (lazy[node] != 0) {
		// Ȧ����: ^���� 1��
		// ¦����: 0��
		tree[node] ^= ((e - s + 1) % 2) * lazy[node];
		if (s != e) {
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}
int init(vector<int>& tree, int node, int s, int e) {
	if (s == e)
		return tree[node] = a[s];
	int mid = (s + e) / 2;
	return tree[node] = init(tree, node * 2, s, mid)
		^ init(tree, node * 2 + 1, mid + 1, e);
}
// �������� query
int query(vector<int>& tree, vector<int>& lazy, 
	int node, int s, int e, int left, int right) {
	// lazyprop ���ְ�
	update_lazy(tree, lazy, node, s, e);
	// ������ ������� �ƹ��͵� �ƴ� �� ����
	if (e < left || right < s)
		return 0;
	if (left <= s && e <= right)
		return tree[node];
	int mid = (s + e) / 2;
	return query(tree, lazy, node * 2, s, mid, left, right)
		^ query(tree, lazy, node * 2 + 1, mid + 1, e, left, right);
}
// �������� update
void update(vector<int>& tree, vector<int>& lazy, int node,
	int s, int e, int left, int right, int val) {
	update_lazy(tree, lazy, node, s, e);
	if (e < left || right < s)
		return;
	if (left <= s && e <= right) {
		// xor������ Ȧ������ ��= 1��
		tree[node] ^= ((e - s + 1)%2) * val;
		if (s != e) {
			lazy[node*2] ^= val;
			lazy[node * 2 + 1] ^= val;
		}
		return;
	}
	int mid = (s + e) / 2;
	update(tree, lazy, node * 2, s, mid, left, right, val);
	update(tree, lazy, node * 2 + 1, mid + 1, e, left, right, val);
	// tree[node] ������Ʈ���ֱ�
	tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int size = ceil(log2(MAX));
	// 4�� Ȥ...�ø��� ��Ÿ�� ���� ����
	int tree_size = 4 + (1 << (size + 1));
	// tree�� lazy �޸� �ִ��� �۰�
	vector<int> tree(tree_size);
	vector<int> lazy(tree_size);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	init(tree, 1, 0, N - 1);
	cin >> M;
	while (M--) {
		int ch;
		cin >> ch;
		// update
		if (ch == 1) {
			int b, c, d;
			cin >> b >> c >> d;
			if (b > c)
				swap(b, c);
			update(tree, lazy, 1, 0, N - 1, b, c, d);
		}
		// query
		else {
			int b, c;
			cin >> b >> c;
			if (b > c)
				swap(b, c);
			cout << query(tree, lazy, 1, 0, N - 1, b, c) << "\n";
		}
	}
}