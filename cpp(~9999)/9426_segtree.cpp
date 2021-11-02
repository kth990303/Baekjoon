// 210606 #9426 Áß¾Ó°ª ÃøÁ¤ Platinum V
// segtree 0~65535 kth's num
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 2500001;
const int MAX_V = 65536;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
int N, K, a[MAX], tree[1 << 18];
ll ans;
ll query(int node, int s, int e, int idx) {
	if (s == e)
		return s;
	int mid = (s + e) / 2;
	if (tree[node * 2] < idx) {
		// kth's trick
		idx -= tree[node * 2];
		return query(node * 2 + 1, mid + 1, e, idx);
	}
	else {
		return query(node * 2, s, mid, idx);
	}
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
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 0; i < N; i++) {
		if (i >= K)
			update(1, 0, MAX_V - 1, a[i - K], -1);
		cin >> a[i];
		update(1, 0, MAX_V - 1, a[i], 1);
		if (i >= K - 1)
			ans += query(1, 0, MAX_V - 1, (K + 1) / 2);
	}
	cout << ans << "\n";
}