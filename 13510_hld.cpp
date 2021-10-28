// 211028 #13510 Æ®¸®¿ÍÄõ¸®1 Platinum I
// HLD(Standard)
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
const ll LNF = 0x3f3f3f3f3f3f3f3f;
int N, M;
vector<pi> edge, v[MAX];
vector<int> c[MAX];
int tmpw[MAX], tree[1 << 18];
int init(int node, int s, int e) {
	if (s == e)
		return tree[node] = tmpw[s];
	int mid = (s + e) / 2;
	return tree[node] = max(init(node * 2, s, mid),
		init(node * 2 + 1, mid + 1, e));
}
int query(int node, int s, int e, int left, int right) {
	if (e < left || right < s)
		return -INF;
	if (left <= s && e <= right)
		return tree[node];
	int mid = (s + e) / 2;
	return max(query(node * 2, s, mid, left, right),
		query(node * 2 + 1, mid + 1, e, left, right));
}
void update(int node, int s, int e, int idx, int val) {
	if (e < idx || idx < s)
		return;
	if (e == idx && idx == s) {
		tree[node] = val;
		return;
	}
	int mid = (s + e) / 2;
	update(node * 2, s, mid, idx, val);
	update(node * 2 + 1, mid + 1, e, idx, val);
	tree[node] = max(tree[node * 2], tree[node * 2 + 1]);
}
int sz[MAX], d[MAX], p[MAX], t[MAX], in[MAX], out[MAX], tmp;
int w[MAX];
bool visit[MAX];
void dfs(int cur) {
	visit[cur] = true;
	for (auto i : v[cur]) {
		if (!visit[i.second]) {
			c[cur].push_back(i.second);
			w[i.second] = i.first;
			dfs(i.second);
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
	for (auto i : c[cur]) {
		if (i == c[cur][0])
			t[i] = t[cur];
		else
			t[i] = i;
		dfs2(i);
	}
	out[cur] = tmp;
}
int hldQuery(int n1, int n2) {
	int ret = -INF;
	while (t[n1] != t[n2]) {
		if (d[t[n1]] > d[t[n2]])
			swap(n1, n2);
		int top = t[n2];
		ret = max(ret, query(1, 1, N, in[top], in[n2]));
		n2 = p[top];
	}
	if (d[n1] > d[n2])
		swap(n1, n2);
	for (auto i : c[n1]) {
		if (t[i] == t[n1]) {
			n1 = i;
			break;
		}
	}
	ret = max(ret, query(1, 1, N, in[n1], in[n2]));
	return ret;
}
void hldUpdate(int idx, int val) {
	int idx1 = edge[idx].first;
	int idx2 = edge[idx].second;
	if (d[idx1] < d[idx2])
		update(1, 1, N, in[idx2], val);
	else
		update(1, 1, N, in[idx1], val);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int n1, n2, cost;
		cin >> n1 >> n2 >> cost;
		v[n1].push_back({ cost, n2 });
		v[n2].push_back({ cost, n1 });
		edge.push_back({ n1, n2 });
	}
	dfs(1);
	dfs1(1);
	dfs2(1);
	for (int i = 1; i <= N; i++) {
		tmpw[in[i]] = w[i];
	}
	init(1, 1, N);
	cin >> M;
	while (M--) {
		int ch, a, b;
		cin >> ch >> a >> b;
		if (ch == 1)
			hldUpdate(a - 1, b);
		else
			cout << hldQuery(a, b) << "\n";
	}
}