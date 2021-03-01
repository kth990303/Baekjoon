// 210302 #3392 화성 지도 Platinum III
// Plane Sweeping (Standard)
// lazyseg도 될 거 같은데, segtree로도 됨(#19951과 유사한 아이디어)
#include <iostream>
#include <algorithm>
#include <vector>
#define all(v) v.begin(), v.end()
const int MAX = 30001;
using namespace std;
struct map {
	int x, y1, y2, flag;
};
map m[MAX * 2];
int N, tree[1 << 17], ans, res[1 << 17];
// reorder by x-coordinate value
bool cmp(map m1, map m2) {
	return m1.x < m2.x;
}
void update(int node, int s, int e, int left, int right, int val) {
	if (e < left || right < s)
		return;
	if (left <= s && e <= right)
		tree[node] += val;
	// s~e != left~right and don't add val
	// so if and else
	else {
		int mid = (s + e) / 2;
		update(node * 2, s, mid, left, right, val);
		update(node * 2 + 1, mid + 1, e, left, right, val);
	}
	// if there are square,
	if (tree[node])
		res[node] = e - s + 1;
	// else if leaf node
	else if (s == e)
		res[node] = 0;
	else
		res[node] = res[node * 2] + res[node * 2 + 1];
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int x1, y1, x2, y2;
		cin >> x1 >> y1 >> x2 >> y2;
		m[i] = { x1,y1,y2,1 };
		m[i + N] = { x2,y1,y2,-1 };
	}
	sort(m, m + N * 2, cmp);
	int cur = m[0].x, next = m[0].x;
	for (int i = 0; i < N * 2; i++) {
		next = m[i].x;
		ans += (next - cur) * res[1];
		update(1, 0, MAX, m[i].y1, m[i].y2 - 1, m[i].flag);
		cur = m[i].x;
	}
	cout << ans << "\n";
}