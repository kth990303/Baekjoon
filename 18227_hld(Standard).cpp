// 210819 #18227 성대나라의 물탱크 Platinum III
// HLD + lazyprop O(Nlg^2N)
#include <iostream>
#include <algorithm>
#include <vector>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
const int MAX = 200001;
struct Tree {
	ll val, lazy;
};
ll N, C, Q;
Tree tree[1 << 19];
vector<int> v[MAX], c[MAX];
void update_lazy(int node, int s, int e) {
	if (tree[node].lazy) {
		tree[node].val += ((ll)e - s + 1) * tree[node].lazy;
		if (s != e) {
			tree[node * 2].lazy += tree[node].lazy;
			tree[node * 2 + 1].lazy += tree[node].lazy;
		}
		tree[node].lazy = 0;
	}
}
ll query(int node, int s, int e, int left, int right) {
	update_lazy(node, s, e);
	if (e < left || right < s)
		return 0;
	if (left <= s && e <= right)
		return tree[node].val;
	int mid = (s + e) / 2;
	return query(node * 2, s, mid, left, right)
		+ query(node * 2 + 1, mid + 1, e, left, right);
}
void update(int node, int s, int e, int left, int right, ll diff) {
	update_lazy(node, s, e);
	if (e < left || right < s)
		return;
	if (left <= s && e <= right) {
		tree[node].lazy += diff;
		update_lazy(node, s, e);
		return;
	}
	int mid = (s + e) / 2;
	update(node * 2, s, mid, left, right, diff);
	update(node * 2 + 1, mid + 1, e, left, right, diff);
	tree[node].val = tree[node * 2].val + tree[node * 2 + 1].val;
}


int sz[MAX], d[MAX], p[MAX], t[MAX], in[MAX], out[MAX], tmp;
bool visit[MAX];
void dfs(int cur) {
	visit[cur] = true;
	for (auto i : v[cur]) {
		if (!visit[i]) {
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
	for (auto i : c[cur]) {
		if (i == c[cur][0])
			t[i] = t[cur];
		else
			t[i] = i;
		dfs2(i);
	}
 	out[cur] = tmp;
}
ll hldQuery(int node) {
	return query(1, 1, N, in[node], in[node]);
}
void hldUpdate(int node) {
	while (t[node] != t[C]) {
		int top = t[node];
		update(1, 1, N, in[top], in[node], 1);
		node = p[top];
	}
	update(1, 1, N, in[C], in[node], 1);
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> C;
	for (int i = 0; i < N - 1; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		v[n1].push_back(n2);
		v[n2].push_back(n1);
	}
	dfs(C); 
	dfs1(C); 
	dfs2(C);
	cin >> Q;
	while (Q--) {
		int ch, A;
		cin >> ch >> A;
		if (ch == 1) {
			hldUpdate(A);
		}
		else {
			cout << hldQuery(A) * ((ll)d[A] + 1) << "\n";
		}
	}
}