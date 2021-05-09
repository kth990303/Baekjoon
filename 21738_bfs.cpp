// 210509 #21738 ¾óÀ½±ú±â Æë±Ï Gold V
// bfs (understanding discription is hard)
// ans: N-two min(P<->S cost)-1
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 328001;
int N, S, P, ans, cnt;
vector<int> v[MAX];
bool visit[MAX];
void bfs(int cur, int num) {
	queue<pair<int, int>> q;
	q.push({ cur, num });
	visit[cur] = true;
	while (!q.empty()) {
		int cur = q.front().first;
		int num = q.front().second;
		q.pop();
		if (cur <= S) {
			cnt++;
			ans -= num;
			if (cnt == 2)
				return;
		}
		for (auto i : v[cur]) {
			if (!visit[i]) {
				visit[i] = true;
				q.push({ i, num + 1 });
			}
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> S >> P;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	ans = N - 1;
	bfs(P, 0);
	cout << ans << "\n";
}