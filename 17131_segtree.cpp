// 210329 #17131 여우가 정보섬에 올라온 이유 Platinum IV
// segtree + sweeping
// different exclude same y-coordination solution -> WA
// this solution -> AC
#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#define all(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
const int MAX = 400001;
const ll MOD = 1e9 + 7;
struct Point {
	ll x, y;
};
Point p[MAX];
vector<ll> v;
ll N, ans, tree[1 << 21];
bool cmp(const Point& p1, const Point& p2) {
	if (p1.y == p2.y)
		return p1.x < p2.x;
	return p1.y < p2.y;
}
ll query(int node, int s, int e, int left, int right) {
	if (e < left || right < s)
		return 0;
	if (left <= s && e <= right)
		return tree[node];
	int mid = (s + e) / 2;
	return (query(node * 2, s, mid, left, right)
		+ query(node * 2 + 1, mid + 1, e, left, right)) % MOD;
}
void update(int node, int s, int e, int idx, ll val) {
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
	//freopen("input.txt", "r", stdin);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> p[i].x >> p[i].y;
		update(1, 0, MAX, p[i].x + 200000, 1);
		v.push_back(p[i].x);
	}
	sort(p, p + N, cmp);
	sort(all(v));
	ll num = MOD;
	for (int i = 0; i < N; i++) {
		if (num != p[i].y) {
			num = p[i].y;
			for (int j = i; j < N; j++) {
				if (p[j].y != num)
					break;
				update(1, 0, MAX, p[j].x + 200000, -1);
			}
		}
		ll left = query(1, 0, MAX, 0, p[i].x + 200000 - 1) % MOD;
		ll right = query(1, 0, MAX, p[i].x + 200000 + 1, MAX * 2 - 1) % MOD;
		ans += left * right;
		ans %= MOD;
	}
	cout << ans << "\n";
}