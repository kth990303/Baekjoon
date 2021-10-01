// 211001 #20933 ∏∂Ω∫≈©∆„≈©2077 Platinum IV
// RMQ seg + sum segtree + binary_search O(Qlg^2(N)))
// confused index because of edge, vertex
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
const ll LNF = 1e18;
int N, a[MAX], t[MAX], Q, C[1 << 19], T[1 << 19];
int init(int node, int s, int e) {
	if (s == e)
		return T[node] = t[s];
	int mid = (s + e) / 2;
	return T[node] = init(node * 2, s, mid) 
		+ init(node * 2 + 1, mid + 1, e);
}
int priceInit(int node, int s, int e) {
	if (s == e)
		return C[node] = a[s];
	int mid = (s + e) / 2;
	return C[node] = min(priceInit(node * 2, s, mid),
		priceInit(node * 2 + 1, mid + 1, e));
}
int query(int node, int s, int e, int left, int right) {
	if (e < left || right < s)
		return 0;
	if (left <= s && e <= right)
		return T[node];
	int mid = (s + e) / 2;
	return query(node * 2, s, mid, left, right)
		+ query(node * 2 + 1, mid + 1, e, left, right);
}
int priceQuery(int node, int s, int e, int left, int right) {
	if (e < left || right < s)
		return INF;
	if (left <= s && e <= right)
		return C[node];
	int mid = (s + e) / 2;
	return min(priceQuery(node * 2, s, mid, left, right)
		,priceQuery(node * 2 + 1, mid + 1, e, left, right));
}
void update(int node, int s, int e, int idx, int diff) {
	if (e < idx || idx < s)
		return;
	T[node] = diff;
	if (s != e) {
		int mid = (s + e) / 2;
		update(node * 2, s, mid, idx, diff);
		update(node * 2 + 1, mid + 1, e, idx, diff);
		T[node] = T[node * 2] + T[node * 2 + 1];
	}
}

int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	memset(C, INF, sizeof(C));
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	priceInit(1, 1, N);
	for (int i = 1; i <= N - 1; i++) {
		cin >> t[i];
	}
	init(1, 1, N - 1);
	cin >> Q;
	while (Q--) {
		string ch;
		int x, i;
		cin >> ch >> x >> i;
		if (ch == "CALL") {
			int s = x, e = N - 1, res = x - 1, res2 = x;
			while (s <= e) {
				int mid = (s + e) / 2;
				int time = query(1, 1, N - 1, x, mid);
				if (time <= i) {
					res = mid;
					s = mid + 1;
				}
				else
					e = mid - 1;
			}
			res++;
			s = 1, e = x - 1;
			while (s <= e) {
				int mid = (s + e) / 2;
				int time = query(1, 1, N - 1, mid, x - 1);
				if (time <= i) {
					res2 = mid;
					e = mid - 1;
				}
				else
					s = mid + 1;
			}
			cout << priceQuery(1, 1, N, res2, res) << "\n";
		}
		else
			update(1, 1, N - 1, x, i);
	}
}