// 210207 #1168 요세푸스 문제2 Platinum V
// josephus problem segment tree
// why Platinum V? Platinum IV ~ Platinum III
// Want to change kth number -> search kth number -> segtree
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 100001;
int N, K, a[MAX], tree[1 << 18];
// Want kth number? All number 1 and erase 0
int init(int node, int s, int e) {
	if (s == e) {
		return tree[node] = a[s];
	}
	int mid = (s + e) / 2;
	return tree[node] = init(node * 2, s, mid)
		+ init(node * 2 + 1, mid + 1, e);
}
int query(int node, int s, int e, int idx) {
	// only change 1->0
	// don't need to create update function
	// cause the query is recursive anyway
	tree[node]--;
	if (s == e)
		return s;
	int mid = (s + e) / 2;
	if (idx <= tree[node * 2])
		return query(node * 2, s, mid, idx);
	// checking idx is bigger than all left nodes
	return query(node * 2 + 1, mid + 1, e, idx - tree[node * 2]);
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		a[i] = 1;
	}
	init(1, 1, N);
	cout << "<";
	int k = K;
	for (int i = 0; i < N - 1; i++) {
		cout << query(1, 1, N, k) << ", ";
		int size = tree[1];
		// itself changes 0
		// so not +=K. except itself, so K-1
		k += K - 1;
		k %= size;
		// if k%=size==0, end of number
		if (!k)
			k = size;
	}
	cout << query(1, 1, N, k) << ">";
}