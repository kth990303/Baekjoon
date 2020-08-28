// 200828 #3653 ��ȭ���� Platinum IV
// queue ������ Ž��: 100*O(NM)=100*O(N^2)
// segment tree �̿�-> ���� ��
// ó���� lazy propagation ���÷���
// �� ������ update idx�� �� ���� �ְ�(�ٲ�� �� 2��)
// ����������, ���� �߸�¥�� ÷���� �ٽ�^^...
// �׷��ٰ� �� ���������� �ٽ�...
// ������ ���� �ʿ��ҵ�
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
const int MAX = 200001;	// N+M. �̰� �� ���ø��� �������
using namespace std;
int a[MAX];	// DVD node index ����
int N, M;
int init(vector<int>& tree, int node, int s, int e) {
	if (s == e) {
		if (s > M) {
			a[s-M] = s;
			tree[node] = 1;
		}
		return tree[node];
	}
	int mid = (s + e) / 2;
	return tree[node] = init(tree, node * 2, s, mid)
		+ init(tree, node * 2 + 1, mid + 1, e);
}
int query(vector<int>& tree, int node, int s, int e, int left, int right) {
	if (e < left || right < s)
		return 0;
	if (left <= s && e <= right) {
		return tree[node];
	}
	int mid = (s + e) / 2;
	return query(tree, node * 2, s, mid, left, right)
		+ query(tree, node * 2 + 1, mid + 1, e, left, right);
}
void update(vector<int>& tree, int node, int s, int e, int idx, int num) {
	if (idx > e || idx < s)
		return;
	if (s==e) {
		tree[node] = num;
		return;
	}
	int mid = (s + e) / 2;
	update(tree, node * 2, s, mid, idx, num);
	update(tree, node * 2 + 1, mid + 1, e, idx, num);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int size = ceil(log2(MAX));
	int tree_size = 4 + (1 << (size + 1));
	
	/*
	2
	3 3
	3 1 1
	5 3
	4 4 5
	ans
	2 1 0
	3 0 4
	*/
	int t;
	cin >> t;
	while (t--) {
		cin >> N >> M;
		vector<int> tree(tree_size, 0);
		fill(a, a + MAX, 0);

		init(tree, 1, 1, M+N);
		for (int i = 1; i <= M; i++) {
			int movie;
			cin >> movie;
			// update �����. ���� �� �����غ���
			cout << query(tree, 1, 1, M + N, 1, a[movie] - 1) << " ";
			// a[movie]�� 0�� �� ��, M-i+1�� movie�� �� �Ÿ� ������Ʈ
			// ������Ʈ�� �Ѳ����� �������� ������ ����.....
			update(tree, 1, 1, M + N, a[movie], 0);
			a[movie] = M - i + 1;
			update(tree, 1, 1, M+N, a[movie], 1);
		}
		cout << "\n";
	}
}