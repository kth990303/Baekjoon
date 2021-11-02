// 200923 #4803 트리 Gold IV
// 트리가 아닐 때의 처리
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int N, M, cnt;
const int MAX = 501;
vector<int> v[MAX];
bool visit[MAX];
int pre[MAX];
// dfs로 했더니 자꾸 틀림 (200923 기준)
// 그래서 bfs로 했더니 맞음(...)
bool bfs(int cur) {
	queue<int> q;
	q.push(cur);
	visit[cur] = true;
	bool flag = true;	// 트리인지의 여부
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto i : v[x]) {
			if (!visit[i]) {
				visit[i] = true;
				pre[i] = x;
				q.push(i);
			}
			// 싸이클이 존재하는 경우
			// 결국 자신의 부모가 두개인 경우 (루트는 하나이므로)
			else if (i != pre[x])
				flag = false;
		}
	}
	return flag;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int tc = 1;
	while (cin >> N >> M) {
		if (!N && !M)
			break;
		// 초기화
		for (auto& i : v)
			i.clear();
		fill(visit, visit + MAX, false);
		// 트리 아닌 경우가 존재하므로
		// 부모 노드를 담는 배열이 필요함
		fill(pre, pre + MAX, -1);
		cnt = 0;
		// 트리 구현
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		// 트리 순회
		for (int i = 1; i <= N; i++) {
			if (!visit[i]) {
				if (bfs(i))
					cnt++;
			}
		}
		// 답을 출력함
		if (!cnt)
			cout << "Case " << tc << ": No trees.\n";
		else if (cnt == 1)
			cout << "Case " << tc << ": There is one tree.\n";
		else
			cout << "Case " << tc << ": A forest of " << cnt << " trees.\n";
		tc++;
	}
}