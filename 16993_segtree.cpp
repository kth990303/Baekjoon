// 211025 #16993 ¿¬¼ÓÇÕ°úÄõ¸® Platinum II
// segtree, prefix_sum_segtree (±Ý±¤¼¼±×)
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
const int MAX = 100011;
const double INF = 0x3f3f3f3f;
const int LNF = 1e16;
const int MOD = 1e9 + 7;
struct Node {
	ll lsum, rsum, sum, maxsum;
};
Node tree[1 << 18];
ll N, M, a[MAX];
Node merge(Node A, Node B) {
	return {
		max(A.lsum, A.sum + B.lsum),
		max(B.rsum, B.sum + A.rsum),
		A.sum + B.sum,
		max({ A.maxsum,B.maxsum,A.rsum + B.lsum })
	};
}
Node init(int node, int s, int e) {
	if (s == e)
		return tree[node] = { a[s], a[s], a[s], a[s] };
	int mid = (s + e) / 2;
	return tree[node] = merge(init(node * 2, s, mid),
		init(node * 2 + 1, mid + 1, e));
}
Node query(int node, int s, int e, int left, int right) {
	if (e < left || right < s)
		return { -LNF,-LNF, -LNF,-LNF };
	if (left <= s && e <= right)
		return tree[node];
	int mid = (s + e) / 2;
	return merge(query(node * 2, s, mid, left, right),
		query(node * 2 + 1, mid + 1, e, left, right));
}
void update(int node, int s, int e, int idx, ll val) {
	if (e < idx || idx < s)
		return;
	tree[node].lsum += val;
	tree[node].rsum += val;
	tree[node].sum += val;
	tree[node].maxsum += val;
	if (s != e) {
		int mid = (s + e) / 2;
		update(node * 2, s, mid, idx, val);
		update(node * 2 + 1, mid + 1, e, idx, val);
		tree[node] = merge(tree[node * 2], tree[node * 2 + 1]);
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i <= N; i++)
		cin >> a[i];
	init(1, 1, N);
	cin >> M;
	while (M--) {
		int x, y;
		cin >> x >> y;
		cout << query(1, 1, N, x, y).maxsum << "\n";
	}
}