// 201230 #13306 Æ®¸® Platinum V
// union-find (disjoint set)
// a.k.a Offline_query O(QlgN)
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
const int MAX = 200001;
// Not erase E, reverse query and add E.
// Reverse Query -> Need two parents arrays
// p[MAX]: reverse query parents array
// parent[MAX]: original parents array
int N, Q, p[MAX], query[MAX * 2][3], parent[MAX];
int find(int a) {
	if (a == p[a])
		return a;
	return p[a] = find(p[a]);
}
// It's correct to use void type, 
// but it doesn't matter if it's bool type.
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return false;
	p[b] = a;
	return true;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> Q;
	parent[1] = 1;
	for (int i = 2; i <= N; i++) {
		cin >> parent[i];
	}
	int cnt = N - 1 + Q;
	for (int i = 0; i < N - 1 + Q; i++) {
		cin >> query[i][0];
		if (!query[i][0]) {
			cin >> query[i][1];
		}
		else {
			cin >> query[i][1] >> query[i][2];
		}
	}
	// Query (0) is called N-1, so at first, there are no lines.
	stack<bool> ans;	// To remember because it goes back to the query
	for (int i = 1; i <= N; i++) {
		p[i] = i;
	}
	for (int i = N - 2 + Q; i >= 0; i--) {
		if (!query[i][0]) {
			// line connections
			merge(parent[query[i][1]], query[i][1]);
		}
		else {
			// check the same components
			int u = find(query[i][1]);
			int v = find(query[i][2]);
			ans.push(u == v);
		}
	}
	// print answer
	while (!ans.empty()) {
		if (ans.top())
			cout << "YES\n";
		else
			cout << "NO\n";
		ans.pop();
	}
}