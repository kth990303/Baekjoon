// 210915 #1280 나무심기 Platinum IV
// segtree (cnt segtree, sum segtree)
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
typedef pair<int, ll> pi;
typedef pair<int, pi> pii;
const int MAX = 200001;
const int MOD = 1e9 + 7;
ll N, a[MAX], ans = 1;
vector<ll> tree, cnt;
ll query(vector<ll>& t, int node, int s, int e, int left, int right) {
	if (e < left || right < s)
		return 0;
	if (left <= s && e <= right)
		return t[node];
	int mid = (s + e) / 2;
	return query(t, node * 2, s, mid, left, right)
		+ query(t, node * 2 + 1, mid + 1, e, left, right);
}
void update(vector<ll>& t, int node, int s, int e, int idx, ll val) {
	if (e < idx || idx < s)
		return;
	t[node] += val;
	if (s != e) {
		int mid = (s + e) / 2;
		update(t, node * 2, s, mid, idx, val);
		update(t, node * 2 + 1, mid + 1, e, idx, val);
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	tree.resize(1 << 19);
	cnt.resize(1 << 19);
	cin >> a[1];
	update(cnt, 1, 0, MAX, a[1], 1);
	update(tree, 1, 0, MAX, a[1], a[1]);
	for (int i = 2; i <= N; i++) {
		cin >> a[i];
		ll leftCnt = query(cnt, 1, 0, MAX, 0, a[i] - 1);
		ll rightCnt = query(cnt, 1, 0, MAX, a[i] + 1, MAX);
		ll leftSum = query(tree, 1, 0, MAX, 0, a[i] - 1);
		ll rightSum = query(tree, 1, 0, MAX, a[i] + 1, MAX);
		ll num = a[i] * leftCnt - leftSum;
		num += rightSum - a[i] * rightCnt;
		num %= MOD;
		ans *= num;
		ans %= MOD;		
		update(cnt, 1, 0, MAX, a[i], 1);
		update(tree, 1, 0, MAX, a[i], a[i]);
	}
	cout << ans << "\n";
}