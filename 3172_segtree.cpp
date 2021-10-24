// 211024 #3172 현주와윤주의재미있는단어게임 Platinum III
// segtree (inversion_counting)
// Trie? -> compare O(N^2)
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
const double INF = 0x3f3f3f3f;
const int LNF = 1e18;
const int MOD = 1e9 + 7;
int N, tree[1 << 18];
string s[MAX];
vector<pair<string, int>> v;
int query(int node, int s, int e, int left, int right) {
	if (e < left || right < s)
		return 0;
	if (left <= s && e <= right)
		return tree[node];
	int mid = (s + e) / 2;
	return query(node * 2, s, mid, left, right)
		+ query(node * 2 + 1, mid + 1, e, left, right);
}
void update(int node, int s, int e, int idx, int val) {
	if (e < idx || idx < s)
		return;
	tree[node] += val;
	if (s != e) {
		int mid = (s + e) / 2;
		update(node * 2, s, mid, idx, val);
		update(node * 2 + 1, mid + 1, e, idx, val);
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> s[i];
	sort(s, s + N);
	for (int i = 0; i < N; i++) {
		reverse(all(s[i]));
		v.push_back({ s[i], i });
	}
	sort(all(v));
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		ans += 1LL * query(1, 0, N - 1, v[i].second + 1, N - 1);
		update(1, 0, N - 1, v[i].second, 1);
	}
	cout << ans << "\n";
}