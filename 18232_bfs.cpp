// 210131 #18232 텔레포트 정거장 Silver II
// bfs
#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 300001;
int N, M, S, E, ans;
vector<int> v[MAX];
bool visit[MAX];
void bfs(int cur, int time) {
	queue <pair<int, int>> q;
	q.push({ cur, time });
	visit[cur] = true;
	while (!q.empty()) {
		int cur = q.front().first;
		int time = q.front().second;
		visit[cur] = true;
		q.pop();
		if (cur == E) {
			ans = time;
			return;
		}
		if (cur>=1 && !visit[cur - 1]) {
			q.push({ cur - 1, time + 1 });
			// Necessarily visit here!!
			// else: 68% TLE
			visit[cur-1] = true;
		}
		if (cur+1<MAX && !visit[cur + 1]) {
			q.push({ cur + 1, time + 1 });
			visit[cur+1] = true;
		}
		for (auto i : v[cur]) {
			if (!visit[i]) {
				q.push({ i, time + 1 });
				visit[i] = true;
			}
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M >> S >> E;
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		// Not DAG. Undirected!
		v[s].push_back(e);
		v[e].push_back(s);
	}
	bfs(S, 0);
	cout << ans << "\n";
}