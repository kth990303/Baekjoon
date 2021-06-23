// 210623 #19646 Random Generator Platinum V
// kth segtree
#include <iostream>
#include <algorithm>
#include <string>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 200001;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
int N, a[MAX], p[MAX], tree[1 << 19];
int init(int node, int s, int e) {
	if (s == e)
		return tree[node] = a[s];
	int mid = (s + e) / 2;
	return tree[node] = init(node * 2, s, mid)
		+ init(node * 2 + 1, mid + 1, e);
}
int query(int node, int s, int e, int idx) {
	if (s == e)
		return s;
	int mid = (s + e) / 2;
	if (idx <= tree[node * 2])
		return query(node * 2, s, mid, idx);
	return query(node * 2 + 1, mid + 1, e, idx - tree[node * 2]);
}
void update(int node, int s, int e, int idx, int diff) {
	if (e < idx || idx < s)
		return;
	tree[node] += diff;
	if (s != e) {
		int mid = (s + e) / 2;
		update(node * 2, s, mid, idx, diff);
		update(node * 2 + 1, mid + 1, e, idx, diff);
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	init(1, 1, N);
	for (int i = 0; i < N; i++) {
		int n;
		cin >> n;
		int k = query(1, 1, N, n);
		cout << k << " ";
		update(1, 1, N, k, -a[k]);
	}
}