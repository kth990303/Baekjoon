// 210316 #2336 ±²ÀåÇÑ ÇÐ»ý Platinum II
// segtree + sweeping
// o(nlogn)

// idea: sorting first test score
// tree: 1 ~ second test score is better than a[i]
// if third score is also better, a[i] is not great student
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 500001;
const int INF = 1e9 + 7;
struct Person {
	int s1, s2, s3;
};
bool cmp(Person p1, Person p2) {
	return p1.s1 < p2.s1;
}
Person a[MAX];
int N, tree[1 << 20];
int query(int node, int s, int e, int left, int right) {
	if (e < left || right < s)
		return INF;
	if (left <= s && e <= right)
		return tree[node];
	int mid = (s + e) / 2;
	return min(query(node * 2, s, mid, left, right),
		query(node * 2 + 1, mid + 1, e, left, right));
}
void update(int node, int s, int e, int idx, int val) {
	if (e < idx || idx < s)
		return;
	// minimum segtree
	tree[node] = min(tree[node], val);
	// or, return tree[node]=min(update, update)
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
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		a[num].s1 = i;
	}
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		a[num].s2 = i;
	}
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		a[num].s3 = i;
	}
	sort(a + 1, a + N + 1, cmp);
	// cause of minimum segtree
	fill(tree, tree + (1 << 20), INF);
	int ans = 1;
	update(1, 1, N, a[1].s2, a[1].s3);
	for (int i = 2; i <= N; i++) {
		// why query is not a[i].s2-1?
		// it's not important because there is no same score
		if (query(1, 1, N, 1, a[i].s2) > a[i].s3)
			ans++;
		update(1, 1, N, a[i].s2, a[i].s3);
	}
	cout << ans << "\n";
}