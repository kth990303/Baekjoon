// 210628 #18352 특정 거리의 도시 찾기 Silver II
// bfs(328ms: O(N+M)), dijkstra(376ms: O(MlgN))
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MAX = 300001;
const int INF = 0x3f3f3f3f;
int N, M, K, X;
vector<int> v[MAX], ans;
bool visit[MAX];
void bfs() {
	queue<pi> q;
	visit[X] = true;
	q.push({ 0, X });
	while (!q.empty()) {
		int cur = q.front().second;
		int d = q.front().first;
		q.pop();
		if (d > K)
			break;
		else if (d == K) {
			ans.push_back(cur);
			continue;
		}
		for (auto i : v[cur]) {
			if (!visit[i]) {
				visit[i] = true;
				q.push({ d + 1, i });
			}
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K >> X;
	while (M--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	bfs();
	if (ans.empty())
		cout << -1 << "\n";
	else {
		sort(all(ans));
		for (auto i : ans)
			cout << i << "\n";
	}
}