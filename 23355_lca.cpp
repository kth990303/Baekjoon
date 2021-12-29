// 211229 #23355 ฐ๘ป็ Platinum IV
// lca + dfs(trick of hld dfs (euler tour))
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
#include <unordered_map>
#include <unordered_set>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MAX = 250011;
const int INF = 0x3f3f3f3f;
const int SIZE = 18;
const ll LNF = 1e16;
const int MOD = 1e9 + 7;
int N, Q, d[MAX], p[MAX][SIZE + 1], in[MAX], out[MAX], tmp;
vector<int> v[MAX];
void init(int cur) {
	in[cur] = ++tmp;
	for (int i : v[cur]) {
		if (d[i] == -1) {
			d[i] = d[cur] + 1;
			p[i][0] = cur;
			init(i);
		}
	}
	out[cur] = tmp;
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
bool check(int lo, int hi, int i, int j) {
	bool flag1 = false, flag2 = false;
	if (lo <= in[i] && out[i] <= hi)
		flag1 = true;
	if (lo <= in[j] && out[j] <= hi)
		flag2 = true;
	return flag1 ^ flag2;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		v[n1].push_back(n2);
		v[n2].push_back(n1);
	}
	memset(p, -1, sizeof(p));
	fill(d, d + MAX, -1);
	d[1] = 0;
	init(1);
	for (int j = 0; j < SIZE; j++) {
		for (int i = 1; i <= N; i++) {
			if (p[i][j] != -1)
				p[i][j + 1] = p[p[i][j]][j];
		}
	}
	cin >> Q;
	while (Q--) {
		int ch, i, j, k, l;
		cin >> ch >> i >> j >> k;
		int lo = in[k], hi = out[k];
		if (ch == 1) {
			if (lca(i, j) == k) {
				cout << "NO\n";
				continue;
			}
			cout << (check(lo, hi, i, j) ? "NO" : "YES") << "\n";
		}
		else {
			cin >> l;
			bool flag1 = true, flag2 = true;
			if (lca(i, j) == k) {
				flag1 = false;
			}
			if(flag1)
				flag1 = !check(lo, hi, i, j);
			lo = in[l], hi = out[l];
			if (lca(i, j) == l) {
				flag2 = false;
			}
			if(flag2)
				flag2 = !check(lo, hi, i, j);
			if (!flag1 && !flag2) {
				cout << "NO\n";
			}
			else {
				cout << "YES\n";
			}
		}
	}
}