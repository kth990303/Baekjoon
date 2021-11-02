// 210625 #7469 K¹øÂ° ¼ö Platinum III
// merge_sort tree + binary_search
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
const int MAX = 100001;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
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
		return upper_bound(all(tree[node]), val) - tree[node].begin();
	int mid = (s + e) / 2;
	return query(node * 2, s, mid, left, right, val)
		+ query(node * 2 + 1, mid + 1, e, left, right, val);
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	init(1, 0, N - 1);
	while (M--) {
		int a, b, idx;
		cin >> a >> b >> idx;
		a--; b--;
		int s = -1e9, e = 1e9, ans = 0;
		while (s <= e) {
			int mid = (s + e) / 2;
			int n = query(1, 0, N - 1, a, b, mid);
			if (n < idx) {
				s = mid + 1;
			}
			else {
				if (n == idx)
					ans = mid;
				e = mid - 1;
			}
		}
		cout << ans << "\n";
	}
}