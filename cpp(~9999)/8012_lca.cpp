// 210310 #8012 한동이는 영업사원! Platinum IV
// lca -> sum of distance
// How did I get this right at once...?
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
const int SIZE = 16;
const int MAX = 30001;
vector<int> v[MAX];
int N, M, d[MAX], p[MAX][SIZE + 1], root = 1, ans;
// lca tree init
void init(int cur) {
	for (auto i : v[cur]) {
		if (d[i] == -1) {
			d[i] = d[cur] + 1;
			p[i][0] = cur;
			init(i);
		}
	}
}
// get lca node
int lca(int a, int b) {
	if (d[a] < d[b])
		swap(a, b);
	int diff = d[a] - d[b];
	int j = 0;
	while (diff) {
		if (diff % 2)
			a = p[a][j];
		diff /= 2;
		j++;
	}
	if (a == b)
		return a;
	for (int j = SIZE; j >= 0; j--) {
		if (p[a][j] != -1 && p[a][j] != p[b][j]) {
			a = p[a][j];
			b = p[b][j];
		}
	}
	a = p[a][0];
	return a;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	memset(p, -1, sizeof(p));
	fill(d, d + MAX, -1);
	d[root] = 0;
	init(root);
	for (int j = 0; j < SIZE; j++) {
		for (int i = 2; i <= N; i++) {
			if (p[i][j] != -1)
				p[i][j + 1] = p[p[i][j]][j];
		}
	}
	cin >> M;
	int a = root, b;
	while (M--) {
		cin >> b;
		int lcaNode = lca(a, b);
		ans += d[a] + d[b] - 2 * d[lcaNode];
		a = b;
	}
	cout << ans << "\n";
}