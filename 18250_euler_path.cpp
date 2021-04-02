// 210402 #18250 Ã¶µµ ¿©Çà Platinum V
// Euler_path: only one time vertex
// check component counts by dfs
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 200001;
int N, M, d[MAX], cnt, ans;
vector<int> v[MAX];
bool visit[MAX];
void dfs(int cur) {
	for (auto i : v[cur]) {
		if (!visit[i]) {
			visit[i] = true;
			dfs(i);
		}
	}
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
		d[a]++;
		d[b]++;
	}
	for (int i = 1; i <= N; i++) {
		if (d[i] % 2)
			cnt++;
	}
	if (cnt <= 2)
		ans = 1;
	else
		ans = cnt / 2;
	int ans2 = 0;
	for (int i = 1; i <= N; i++) {
		if (d[i] && !visit[i]) {
			visit[i] = true;
			dfs(i);
			ans2++;
		}
	}
	cout << max(ans, ans2) << "\n";
}