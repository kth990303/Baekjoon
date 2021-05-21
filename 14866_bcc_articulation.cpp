// 210521 #14866 산만한 고양이 Platinum I
// BCC algorithm (graph cycle, articulation)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int MAX = 300001;
int N, M, d[MAX], p[MAX], id, c[MAX];
int root = 1;
ll ans;
vector<int> v[MAX];
// refer to koosaga's bcc algorithm
void dfs(int cur, int prev) {
	p[cur] = d[cur] = ++id;
	for (auto i : v[cur]) {
		if (i == prev)
			continue;
		if (!d[i]) {
			dfs(i, cur);
			p[cur] = min(p[cur], p[i]);
			if (p[i] >= d[cur])
				c[cur]++;
		}
		else {
			p[cur] = min(p[cur], d[i]);
		}
	}
	c[cur] += 2;
	// if root, not indegree
	if (cur == root)
		--c[cur];
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
	dfs(root, -1);
	for (int i = 1; i <= N; i++) {
		// tree: N=M+1
		// erase v[i].size() -> plus v[i].size()+1 components
		if (N - c[i] == M - v[i].size())
			ans += ll(i);
	}
	cout << ans << "\n";
}