// 210722 #5014 스타트링크 Gold V
// bfs O(N)
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
const int MAX = 1000001;
const int INF = 0x3f3f3f3f;
int F, S, G, U, D;
bool visit[MAX];
int bfs(int x) {
	queue<pi> q;
	q.push({ 0, S });
	visit[S] = true;
	while (!q.empty()) {
		int cur = q.front().second;
		int time = q.front().first;
		q.pop();
		if (cur == G)
			return time;
		if (cur + U <= F && !visit[cur + U]) {
			visit[cur + U] = true;
			q.push({ time + 1, cur + U });
		}
		if (cur - D >= 1 && !visit[cur - D]) {
			visit[cur - D] = true;
			q.push({ time + 1, cur - D });
		}	
	}
	return -1;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> F >> S >> G >> U >> D;
	if ((!D && G < S) || (!U && G > S)) {
		cout << "use the stairs\n";
		return 0;
	}
	int ans = bfs(S);
	if (ans == -1)
		cout << "use the stairs\n";
	else
		cout << ans << "\n";
}