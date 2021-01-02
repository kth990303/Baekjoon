// 210102 #12851 ¼û¹Ù²ÀÁú2 Gold V
// BFS (queue)
#include <iostream>
#include <queue>
using namespace std;
const int MAX = 200001;
int N, K, ans = 1e9 + 7, cnt;
bool visit[MAX];
void bfs(int x) {
	queue<pair<int, int>> q;
	q.push({ x, 0 });
	visit[x] = true;
	while (!q.empty()) {
		int n = q.front().first;
		int time = q.front().second;
		// protect the same time visit if the different time 
		// ex) time: 4 ->visit[17] ->when time5, not queued 17
		visit[n] = true;
		q.pop();
		// queue orders by time
		if (time > ans)
			break;
		if (n == K) {
			if (!cnt)
				ans = time;
			cnt++;
			continue;
		}
		// Do not handle visit, between the same time
		if (!visit[n + 1] && n + 1 <= K + 1) {
			q.push({ n + 1, time + 1 });
		}
		if (!visit[2 * n] && 2 * n <= K + 1) {
			q.push({ 2 * n, time + 1 });
		}
		if (!visit[n - 1] && n) {
			q.push({ n - 1, time + 1 });
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	bfs(N);
	cout << ans << "\n" << cnt << "\n";
}