// 210806 #2517 ´Þ¸®±â Platinum IV
// lower_bound + segtree (inversion counting)
#include <iostream>
#include <vector>
#include <algorithm>
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const int MAX = 500001;
vector<int> v;
int N, a[MAX], tree[1 << 20];
int query(int node, int s, int e, int left, int right) {
	if (e < left || right < s)
		return 0;
	if (left <= s && e <= right)
		return tree[node];
	int mid = (s + e) / 2;
	return query(node * 2, s, mid, left, right)
		+ query(node * 2 + 1, mid + 1, e, left, right);
}
void update(int node, int s, int e, int idx, int val) {
	if (e < idx || idx < s)
		return;
	tree[node] += val;
	if (s != e) {
		int mid = (s + e) / 2;
		update(node * 2, s, mid, idx, val);
		update(node * 2 + 1, mid + 1, e, idx, val);
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	v.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> v[i];
		a[i] = v[i];
	}
	sort(all(v));
	for (int i = 1; i <= N; i++) {
		a[i] = lower_bound(all(v), a[i]) - v.begin() + 1;
		cout << i - query(1, 1, N, 1, a[i] - 1) << "\n";
		update(1, 1, N, a[i], 1);
	}
}