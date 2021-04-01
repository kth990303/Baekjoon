// 210401 #3584 가장 가까운 공통조상 Gold IV
// only one query -> not need lca 
// but, I want to practice lca O(lgN), so this is lca solution
#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
const int SIZE = 15;
const int MAX = 10001;
vector<int> v[MAX];
int N, d[MAX], p[MAX][SIZE + 1], root;
bool visit[MAX];
void init(int cur) {
	for (auto i : v[cur]) {
		if (d[i] == -1) {
			d[i] = d[cur] + 1;
			p[i][0] = cur;
			init(i);
		}
	}
}
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
	return p[a][0];
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		for (auto& i : v) {
			i.clear();
		}
		fill(visit, visit + MAX, false);
		cin >> N;
		for (int i = 0; i < N - 1; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
			visit[b] = true;
		}
		for (int i = 1; i <= N; i++) {
			if (!visit[i]) {
				root = i;
				break;
			}
		}
		memset(p, -1, sizeof(p));
		fill(d, d + MAX, -1);
		d[root] = 0;
		init(root);
		for (int j = 0; j < SIZE; j++) {
			for (int i = 1; i <= N; i++) {
				if (i == root)
					continue;
				if (p[i][j] != -1)
					p[i][j + 1] = p[p[i][j]][j];
			}
		}
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << "\n";
	}
}