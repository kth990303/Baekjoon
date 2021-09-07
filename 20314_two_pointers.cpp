// 210907 #20314 ´ëÈ«¼ö Platinum III
// two_pointers, update? -> you can update list by seg query
// O(NlgN)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <set>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
const int MAX = 200001;
int N, a[MAX], t[MAX], tree[1 << 19], ans[MAX];
int init(int node, int s, int e) {
	if (s == e)
		return tree[node] = a[s];
	int mid = (s + e) / 2;
	return tree[node] = max(init(node * 2, s, mid),
		init(node * 2 + 1, mid + 1, e));
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
	tree[node] = val;
	if (s != e) {
		int mid = (s + e) / 2;
		update(node * 2, s, mid, idx, val);
		update(node * 2 + 1, mid + 1, e, idx, val);
		tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		ans[i] = a[i];
	}
	init(1, 1, N);
	for (int i = 1; i < N; i++) {
		cin >> t[i];
	}
	int s = 1, e = 1, time = 0;
	while (s != N) {
		if (e < N && time + t[e] <= a[e+1]) {
			ans[s] = max(ans[s], query(1, 1, N, s, e + 1));
			time += t[e];
			e++;
		}
		else {
			ans[s] = max(ans[s], query(1, 1, N, s, e));
			time -= t[s];
			s++;
		}
	}
	s = N, e = N, time = 0;
	while (e != 1) {
		if (s > 1 && time + t[s - 1] <= a[s - 1]) {
			ans[e] = max(ans[e], query(1, 1, N, s - 1, e));
			time += t[s - 1];
			s--;
		}
		else {
			ans[e] = max(ans[e], query(1, 1, N, s, e));
			time -= t[e - 1];
			e--;
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << ans[i] << " ";
	}
}