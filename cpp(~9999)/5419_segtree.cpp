// 210227 #5419 ºÏ¼­Ç³ Platinum IV
// segtree + sweeping + coordinate_compression
#include <iostream>
#include <algorithm>
#include <vector>
#define all(v) v.begin(), v.end()
using namespace std;
const int MAX = 75001;
typedef long long ll;
struct Point {
	int x, y;
};
bool cmp(Point p1, Point p2) {
	if (p1.x == p2.x)
		return p1.y > p2.y;
	return p1.x < p2.x;
}
int N, tree[1 << 18];
vector<Point> v;
vector<int> v2;
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
	if (idx < s || e < idx)
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

	int t;
	cin >> t;
	while (t--) {
		cin >> N;
		v.clear();
		v2.clear();
		fill(tree, tree + (1 << 18), 0);
		for (int i = 0; i < N; i++) {
			int x, y;
			cin >> x >> y;
			v.push_back({ x, y });
			v2.push_back(y);
		}
		sort(all(v), cmp);
		sort(all(v2));
		v2.erase(unique(all(v2)), v2.end());
		ll ans = 0;
		for (int i = 0; i < N; i++) {
			int idx = lower_bound(all(v2), v[i].y) - v2.begin();
			ans += (ll)query(1, 0, N - 1, idx, N-1);
			update(1, 0, N-1, idx, 1);
		}
		cout << ans << "\n";
	}
}