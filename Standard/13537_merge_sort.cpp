// 210210 #13537 ¼ö¿­°ú Äõ¸® 1 Platinum IV
// bigger than k? sorting -> merge sort tree
#include <iostream>
#include <algorithm>
#include <vector>
#define all(v) v.begin(), v.end()
using namespace std;
const int MAX = 100001;
int N, M, a[MAX];
vector<int> tree[1 << 18];
void init(int node, int s, int e) {
	if (s == e) {
		tree[node].push_back(a[s]);
		return;
	}
	int mid = (s + e) / 2;
	init(node * 2, s, mid);
	init(node * 2 + 1, mid + 1, e);
	auto& l = tree[node * 2], & r = tree[node * 2 + 1];
	merge(all(l), all(r), back_inserter(tree[node]));
}
int query(int node, int s, int e, int left, int right, int val) {
	if (e < left || right < s)
		return 0;
	if (left <= s && e <= right)
		return tree[node].end() - upper_bound(all(tree[node]), val);
	int mid = (s + e) / 2;
	return query(node * 2, s, mid, left, right, val)
		+ query(node * 2 + 1, mid + 1, e, left, right, val);
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	init(1, 0, N - 1);
	cin >> M;
	while (M--) {
		int s, e, k;
		cin >> s >> e >> k;
		s--; e--;
		cout << query(1, 0, N - 1, s, e, k) << "\n";
	}
}