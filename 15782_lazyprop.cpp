// 200909 #15782 Calculate! 2 Platinum III
// ���������� ��2�� ���� �����ٰ� ����
// lazyprop+������ȸ (�ڽı��� ��� �����ǵ���)
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
const int MAX = 100001;
int N, M, a[MAX], d[MAX], cnt = 1;
int numChild[MAX], id[MAX];
vector<int> v[MAX];
bool used[MAX];
// ���� ��ȸ
// �ڽı��� �� ������Ʈ�Ϸ���
// �ڽ��� �͵��� �θ𺸴� �տ� �ֵ���
int init_tree(int cur) {
	// ���� �� ó�� �Ϸ�
	used[cur] = true;
	// ���� ���� �ڽ� �� ����
	int child = 0;
	for (auto i : v[cur]) {
		// �ڽ� Ž��
		if (!used[i])
			child += init_tree(i);
	}
	// ����ġ�� �� Ʈ�� ������
	a[cnt] = d[cur];
	// ������ �ѹ� �ٿ��ֱ�
	id[cur] = cnt++;
	// ���� �������� �ڽ� �� �� ����
	numChild[cur] = child;
	// �ڽŵ� �ᱹ�� ���������� �ڽ���
	return child + 1;
}
// �������� XOR ���������� �Ȱ���.
int init(vector<int>& tree, int node, int s, int e) {
	if (s == e)
		return tree[node] = a[s];
	int mid = (s + e) / 2;
	return tree[node] = init(tree, node * 2, s, mid)
		^ init(tree, node * 2 + 1, mid + 1, e);
}
void update_lazy(vector<int>& tree, vector<int>& lazy, 
	int node, int s, int e) {
	if (lazy[node]) {
		tree[node] ^= ((e - s + 1) % 2) * lazy[node];
		if (s != e) {
			lazy[node * 2] ^= lazy[node];
			lazy[node * 2 + 1] ^= lazy[node];
		}
		lazy[node] = 0;
	}
}
int query(vector<int>& tree, vector<int>& lazy,
	int node, int s, int e, int left, int right) {
	update_lazy(tree, lazy, node, s, e);
	if (e < left || right < s)
		return 0;
	if (left <= s && e <= right)
		return tree[node];
	int mid = (s + e) / 2;
	return query(tree, lazy, node * 2, s, mid, left, right)
		^ query(tree, lazy, node * 2 + 1, mid + 1, e, left, right);
}
void update(vector<int>& tree, vector<int>& lazy, int node,
	int s, int e, int left, int right, int val) {
	update_lazy(tree, lazy, node, s, e);
	if (e < left || right < s)
		return;
	if (left <= s && e <= right) {
		tree[node] ^= ((e - s + 1) % 2) * val;
		if (s != e) {
			lazy[node * 2] ^= val;
			lazy[node * 2 + 1] ^= val;
		}
		return;
	}
	int mid = (s + e) / 2;
	update(tree, lazy, node * 2, s, mid, left, right, val);
	update(tree, lazy, node * 2 + 1, mid + 1, e, left, right, val);
	tree[node] = tree[node * 2] ^ tree[node * 2 + 1];
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	int size = ceil(log2(N) + 1);
	int tree_size = 1 << size;
	vector<int> tree(tree_size);
	vector<int> lazy(tree_size);
	for (int i = 1; i < N; i++) {
		int p, q;
		cin >> p >> q;
		v[p].push_back(q);
		v[q].push_back(p);
	}
	for (int i = 1; i <= N; i++) {
		cin >> d[i];
	}
	init_tree(1);
	init(tree, 1, 1, N);
	for (int i = 0; i < M; i++) {
		int ch;
		cin >> ch;
		// query
		if (ch == 1) {
			int b;
			cin >> b;
			cout << query(tree, lazy, 1, 1, N, id[b] - numChild[b], id[b]) << "\n";
		}
		// update
		else {
			int b, c;
			cin >> b >> c;
			update(tree, lazy, 1, 1, N, id[b] - numChild[b], id[b], c);
		}
	}
}