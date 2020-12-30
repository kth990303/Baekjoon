// 201230 #13023 ABCDE Gold V
// O(N), not O(N^3)
// DFS
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 2001;
int N, M, ans;
bool visit[MAX];
vector<int> v[MAX];
int dfs(int cur) {
	int depth = 0;
	visit[cur] = true;
	for (auto i : v[cur]) {
		if (!visit[i]) {
			visit[i] = true;
			depth = max(depth, dfs(i) + 1);
			// prevent tle, because of (visit[cur]=false;)
			if (depth >= 4)
				return 4;
		}
	}
	// prevent (if cycle, not enough traversal)
	visit[cur] = false;
	return depth;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < N; i++) {
		fill(visit, visit + MAX, false);
		// dfs
		ans = max(ans, dfs(i));
	}
	if (ans >= 4)
		cout << 1 << "\n";
	else
		cout << 0 << "\n";
}