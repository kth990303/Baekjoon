// 210310 #11658 구간 합 구하기3 Platinum V
// Fenwick Tree practice
// 2D segtree -> fenwick (query sum)
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1025;
int a[MAX][MAX], tree[MAX][MAX], N, M;
int query(int x, int y) {
	int ret = 0, r = x;
	while (r) {
		int c = y;
		while (c) {
			ret += tree[r][c];
			c -= (c & -c);
		}
		r -= (r & -r);
	}
	return ret;
}
void update(int x, int y, int val) {
	int r = x;
	while (r <= N) {
		int c = y;
		while (c <= N) {
			tree[r][c] += val;
			c += (c & -c);
		}
		r += (r & -r);
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> a[i][j];
			update(i, j, a[i][j]);
		}
	}
	while (M--) {
		int ch;
		cin >> ch;
		if (!ch) {
			int r, c, k;
			cin >> r >> c >> k;
			update(r, c, k - a[r][c]);
			a[r][c] = k;
		}
		else {
			int r1, c1, r2, c2;
			cin >> r1 >> c1 >> r2 >> c2;
			cout << query(r2, c2) - query(r2, c1 - 1) - 
				query(r1 - 1, c2) + query(r1 - 1, c1 - 1) << "\n";
		}
	}
}