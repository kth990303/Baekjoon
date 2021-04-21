// 210421 #4256 Æ®¸® Gold IV
// recursion, tree
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <cmath>
#define all(v) (v).begin(), (v).end()
using namespace std;
const int MAX = 1001;
int N, v1[MAX], v2[MAX], a[MAX];
void solve(int idx, int s, int e) {
	if (s > e)
		return;
	int root = v1[idx];
	int pos = a[root];
	solve(idx + 1, s, pos - 1);
	solve(idx + pos - s + 1, pos + 1, e);
	cout << root << " ";
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> v1[i];
		}
		for (int i = 0; i < N; i++) {
			cin >> v2[i];
		}
		for (int i = 0; i < N; i++) {
			a[v2[i]] = i;
		}
		solve(0, 0, N - 1);
		cout << "\n";
	}
}