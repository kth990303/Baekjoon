// 200909 #15782 Calculate! 2 Platinum III
// 개인적으로 플2로 가도 괜찮다고 생각
// lazyprop+후위순회 (자식까지 모두 업뎃되도록)
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
// 후위 순회
// 자식까지 다 업데이트하려면
// 자식인 것들은 부모보다 앞에 있도록
int init_tree(int cur) {
	// 현재 꺼 처리 완료
	used[cur] = true;
	// 현재 꺼의 자식 수 변수
	int child = 0;
	for (auto i : v[cur]) {
		// 자식 탐방
		if (!used[i])
			child += init_tree(i);
	}
	// 가중치가 곧 트리 데이터
	a[cnt] = d[cur];
	// 데이터 넘버 붙여주기
	id[cur] = cnt++;
	// 현재 데이터의 자식 수 값 설정
	numChild[cur] = child;
	// 자신도 결국은 누군가에게 자식임
	return child + 1;
}
// 나머지는 XOR 문제에서랑 똑같음.
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