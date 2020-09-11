// 200911 #16404 주식회사 승범이네 Platinum III
// 트리를 펴주고 이후 lazyprop (feat.#15782)
#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
const int MAX = 100001;
using namespace std;
int N, M, a[MAX], d[MAX], cnt = 1;
int numChild[MAX], id[MAX];	// 트리 넘버, 자식의 개수
vector<int> v[MAX];
bool used[MAX];
// 후위 순회로 트리 펴주기
int init_tree(int cur) {
	used[cur] = true;
	int child = 0;
	for (auto& i : v[cur]) {
		if (!used[i])
			child += init_tree(i);
	}
	a[cnt] = cur;
	id[cur] = cnt++;
	numChild[cur] = child;
	return child + 1;
}
void update_lazy(vector<int>& tree, vector<int>& lazy,
	int node, int s, int e) {
	if (lazy[node]) {
		tree[node] += (e - s + 1) * lazy[node];
		if (s != e) {
			lazy[node * 2] += lazy[node];
			lazy[node * 2 + 1] += lazy[node];
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
		+ query(tree, lazy, node * 2 + 1, mid + 1, e, left, right);
}
void update(vector<int>& tree, vector<int>& lazy,
	int node, int s, int e, int left, int right, int val) {
	update_lazy(tree, lazy, node, s, e);
	if (e < left || right < s)
		return;
	if (left <= s && e <= right) {
		tree[node] += (e - s + 1) * val;
		if (s != e) {
			lazy[node * 2] += val;
			lazy[node * 2 + 1] += val;
		}
		return;
	}
	int mid = (s + e) / 2;
	update(tree, lazy, node * 2, s, mid, left, right, val);
	update(tree, lazy, node * 2 + 1, mid + 1, e, left, right, val);
	tree[node] = tree[node * 2] + tree[node * 2 + 1];
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	int size = ceil(log2(N) + 1);
	int tree_size = 1 << size;
	vector<int> tree(tree_size, 0);
	vector<int> lazy(tree_size, 0);
	for (int i = 1; i <= N; i++) {
		int j;
		cin >> j;
		if(i!=1)
			v[j].push_back(i);
	}
	init_tree(1);
	for (int i = 0; i < M; i++) {
		int ch;
		cin >> ch;
		// update
		if (ch == 1) {
			int b, c;
			cin >> b >> c;
			update(tree, lazy, 1, 1, N, id[b]-numChild[b], id[b], c);
		}
		// query
		else {
			int b;
			cin >> b;
			// id[b]만 출력하면 됨.
			// 난 왜 멍청하게 계속 id[b]-numchild[b]를 했을까...
			cout << query(tree, lazy, 1, 1, N, id[b], id[b]) << "\n";
		}
	}
}