// 211009 #20052 °ýÈ£ ¹®ÀÚ¿­ ? Platinum IV
// prefix_sum + RMQ
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
typedef pair<pi, int> pii;
const int MAX = 100011;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
string s;
int N, M, a[MAX], tree[1 << 18], ans;
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
int main() {
	cin.tie(0)->sync_with_stdio(0);
	
	cin >> s >> M;
	int N = s.length();
	for (int i = 1; i <= N; i++) {
		if (s[i - 1] == '(') {
			a[i] = a[i - 1] + 1;
		}
		else {
			a[i] = a[i - 1] - 1;
		}
	}
	init(1, 1, N);
	while (M--) {
		int lo, hi;
		cin >> lo >> hi;
		if (!(a[hi]-a[lo-1]) && query(1,1,N,lo,hi)>=a[lo-1])
			ans++;
	}
	cout << ans << "\n";
}