// 210103 #12015 가장 긴 증가하는 부분수열2 Gold II
// 1. binary_search 2. segtree
// segment tree solution O(NlgN)
// like Inversing Index segtree
#include <iostream>
#include <algorithm>
using namespace std;
typedef pair<int, int> pii;
const int MAX = 1000001;
int N, tree[1 << 21];
pii d[MAX];
// index: desc
// num: asc
bool cmp(pii p1, pii p2) {
	if (p1.first == p2.first)
		return p1.second > p2.second;
	return p1.first < p2.first;
}
int query(int node, int s, int e, int left, int right) {
	if (e < left || right < s)
		return 0;
	if (left <= s && e <= right)
		return tree[node];
	int mid = (s + e) / 2;
	return max(query(node * 2, s, mid, left, right),
		query(node * 2 + 1, mid + 1, e, left, right));
}
void update(int node, int s, int e, int idx, int val) {
	if (e < idx || idx < s)
		return;
	tree[node] = max(tree[node], val);
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
	// pair<number, index>
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		d[i] = { num, i };
	}
	sort(d, d + N + 1, cmp);
	// Maximum Segment tree Query
	for (int i = 1; i <= N; i++) {
		// max query: 1 ~ index
		int maxNum = query(1, 1, N, 1, d[i].second);
		// update: max+1
		update(1, 1, N, d[i].second, maxNum + 1);
	}
	cout << tree[1] << "\n";
}