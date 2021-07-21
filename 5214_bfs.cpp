// 210718 #5214 È¯½Â Gold I
// dummy node -> bipartite graph -> can go everywhere
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
const int MAX = 101001;
const int INF = 0x3f3f3f3f;
int N, K, M, d[MAX];
vector<int> v[MAX];
bool visit[MAX];
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> K >> M;
	for (int i = N + 1; i <= N + M; i++) {
		for (int j = 0; j < K; j++) {
			int n;
			cin >> n;
			v[n].push_back(i);
			v[i].push_back(n);
		}
	}
	queue<pi> q;
	q.push({ 1,1 });
	visit[1] = true;
	while (!q.empty()) {
		int cost = q.front().first;
		int cur = q.front().second;
		q.pop();
		if (cur == N) {
			cout << 1 + cost / 2 << "\n";
			return 0;
		}
		for (auto i : v[cur]) {
			if (!visit[i]) {
				visit[i] = true;
				q.push({ cost + 1, i });
			}
		}
	}
	cout << -1 << "\n";
}