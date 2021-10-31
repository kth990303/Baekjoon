// 211101 #13512 트리와쿼리3 Platinum I
// min_segtree + hld O(NlgN)
// set solution, kth segtree solution도 존재
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
const int MAX = 100011;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e16;
const int MOD = 1e9 + 7;
int N, M, a[MAX];
vector<int> v[MAX], c[MAX];
int tree[1 << 18];
int init(int node, int s, int e) {
	if (s == e)
		return tree[node] = a[s];
	int mid = (s + e) / 2;
	return tree[node] = min(init(node * 2, s, mid), 
		init(node * 2 + 1, mid + 1, e));
}
int query(int node, int s, int e, int left, int right) {
	if (e < left || right < s)
		return INF;
	if (left <= s && e <= right)
		return tree[node];
	int mid = (s + e) / 2;
	return min(query(node * 2, s, mid, left, right),
		query(node * 2 + 1, mid + 1, e, left, right));
}
void update(int node, int s, int e, int idx, int val) {
	if (e < idx || idx < s)
		return;
	if (idx <= s && e <= idx) {
		tree[node] = val;
		return;
	}
	int mid = (s + e) / 2;
	update(node * 2, s, mid, idx, val);
	update(node * 2 + 1, mid + 1, e, idx, val);
	tree[node] = min(tree[node * 2], tree[node * 2 + 1]);
}
int sz[MAX], d[MAX], t[MAX], p[MAX], in[MAX], out[MAX], tmp, rev[MAX];
bool vis[MAX];
void dfs(int cur) {
	vis[cur] = true;
	for (auto i : v[cur]) {
		if (!vis[i]) {
			c[cur].push_back(i);
			dfs(i);
		}
	}
}
void dfs1(int cur) {
	sz[cur] = 1;
	for (auto& i : c[cur]) {
		d[i] = d[cur] + 1;
		p[i] = cur;
		dfs1(i);
		sz[cur] += sz[i];
		if (sz[i] > sz[c[cur][0]])
			swap(i, c[cur][0]);
	}
}
void dfs2(int cur) {
	in[cur] = ++tmp;
	rev[in[cur]] = cur;
	for (auto i : c[cur]) {
		if (i == c[cur][0])
			t[i] = t[cur];
		else
			t[i] = i;
		dfs2(i);
	}
	out[cur] = tmp;
}
int hldQuery(int n) {
	int ret = INF;
	while (t[1] != t[n]) {
		int top = t[n];
		ret = min(ret, query(1, 1, N, in[top], in[n]));
		n = p[top];
	}
	ret = min(ret, query(1, 1, N, in[1], in[n]));
	return ret;
}
// hld에선 in배열로만 소통하자
void hldUpdate(int i) {
	if (a[i] >= INF) a[i] = in[i];
	else a[i] = INF;
	update(1, 1, N, in[i], a[i]);
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
	dfs(1);
	dfs1(1);
	dfs2(1);
	fill(a, a + MAX, INF);
	init(1, 1, N);
	cin >> M;
	while (M--) {
		int ch, i;
		cin >> ch >> i;
		if (ch == 1)
			hldUpdate(i);
		else {
			int ans = hldQuery(i);
			if (ans >= INF)cout << -1 << "\n";
			// hld에선 in배열로만 소통했으므로 rev로 역함수 리턴
			else cout << rev[ans] << "\n";
		}
	}
}