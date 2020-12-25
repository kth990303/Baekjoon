// 201225 #9466 텀 프로젝트 Gold IV
// DFS (SCC 알고리즘 이용 x 풀이)
#include <iostream>
#include <vector>
const int MAX = 100001;
using namespace std;
int N, cnt;
vector<int> v;
bool visit[MAX];
bool finished[MAX];
void dfs(int x) {
	visit[x] = true;
	if (visit[v[x]] && !finished[v[x]]) {
		// 역추적처럼 보이는 코드이나,
		// 자기 자신의 다음이면 다시 첨인 것을 이용
		// 사이클의 특징
		for (int i = v[x]; i != x; i = v[i])
			cnt++;
		cnt++;
	}
	else if (!visit[v[x]])
		dfs(v[x]);
	finished[x] = true;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		// 초기화 작업
		v.clear();
		fill(visit, visit + MAX, false);
		fill(finished, finished + MAX, 0);
		cnt = 0;

		cin >> N;
		v.resize(N + 1);
		for (int i = 1; i <= N; i++) {
			cin >> v[i];
		}
		for (int i = 1; i <= N; i++) {
			if (!visit[i]) {
				dfs(i);
			}
		}
		cout << N - cnt << "\n";
	}
}