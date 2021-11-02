// 210617 #10999 구간합구하기2 Platinum IV
// lazyprop (144ms)
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 1000001;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
struct Tree {
	ll val, lazy;
};
int N, M, K;
ll a[MAX];
Tree tree[1 << 21];
ll init(int node, int s, int e) {
	if (s == e)
		return tree[node].val = a[s];
	int mid = (s + e) / 2;
	return tree[node].val = init(node * 2, s, mid)
		+ init(node * 2 + 1, mid + 1, e);
}
void update_lazy(int node, int s, int e) {
	if (tree[node].lazy) {
		tree[node].val += ((ll)e - s + 1) * tree[node].lazy;
		if (s != e) {
			tree[node * 2].lazy += tree[node].lazy;
			tree[node * 2 + 1].lazy += tree[node].lazy;
		}
		tree[node].lazy = 0;
	}
}
ll query(int node, int s, int e, int left, int right) {
	update_lazy(node, s, e);
	if (e < left || right < s)
		return 0;
	if (left <= s && e <= right)
		return tree[node].val;
	int mid = (s + e) / 2;
	return query(node * 2, s, mid, left, right)
		+ query(node * 2 + 1, mid + 1, e, left, right);
}
void update(int node, int s, int e, int left, int right, ll diff) {
	update_lazy(node, s, e);
	if (e < left || right < s)
		return;
	if (left <= s && e <= right) {
		tree[node].lazy += diff;
		update_lazy(node, s, e);
		return;
	}
	int mid = (s + e) / 2;
	update(node * 2, s, mid, left, right, diff);
	update(node * 2 + 1, mid + 1, e, left, right, diff);
	tree[node].val = tree[node * 2].val + tree[node * 2 + 1].val;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		// if not init and update -> 414ms
	}
	init(1, 1, N);
	for (int i = 0; i < M + K; i++) {
		int ch, b, c;
		ll d;
		cin >> ch >> b >> c;
		if (ch == 1) {
			cin >> d;
			update(1, 1, N, b, c, d);
		}
		else
			cout << query(1, 1, N, b, c) << "\n";
	}
}