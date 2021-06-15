// 210615 #13511 Æ®¸®¿ÍÄõ¸®2 Platinum III
// LCA
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int SIZE = 17;
const int MAX = 100001;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int N, M, d[MAX], p[MAX][SIZE + 1];
ll len[MAX];
vector<pi> v[MAX];
void init(int cur) {
	for (auto i : v[cur]) {
		if (d[i.second] == -1) {
			d[i.second] = d[cur] + 1;
			len[i.second] = len[cur] + i.first;
			p[i.second][0] = cur;
			init(i.second);
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
	a = p[a][0];
	return a;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N-1; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		v[a].push_back({ cost, b });
		v[b].push_back({ cost, a });
	}
	memset(p, -1, sizeof(p));
	fill(d, d + MAX, -1);
	d[1] = 0;
	init(1);
	for (int j = 0; j < SIZE; j++) {
		for (int i = 2; i <= N; i++) {
			if (p[i][j] != -1)
				p[i][j + 1] = p[p[i][j]][j];
		}
	}
	cin >> M;
	while (M--) {
		int ch, a, b, k;
		cin >> ch >> a >> b;
		int pnode = lca(a, b);
		if (ch == 1) {
			cout << len[a] + len[b] - 2 * len[pnode] << "\n";
		}
		else {
			cin >> k;
			k--;
			if (d[a] - d[pnode] >= k) {
				for (int i = 0; k > 0; i++) {
					if (k % 2)
						a = p[a][i];
					k /= 2;
				}
				cout << a << "\n";
			}
			else {
				k -= d[a] - d[pnode];
				k = d[b] - d[pnode] - k;
				for (int i = 0; k > 0; i++) {
					if (k % 2)
						b = p[b][i];
					k /= 2;
				}
				cout << b << "\n";
			}
		}
	}
}