// 201225 #9466 텀 프로젝트 Gold IV
// topology sort 풀이 (dfs, scc 알고리즘 풀이 또한 가능)
// dfs: 584ms / topology: 560ms / scc: 1520ms
// O(N) : O(V+E)
// DAG 이므로 위상정렬 또한 가능
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
const int MAX = 100001;
using namespace std;
vector<int> v;
int in[MAX];	// 위상 정렬이 가능하기까지의 차수
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		fill(in, in + MAX, 0);

		int N, cnt = 0;
		cin >> N;
		v.resize(N + 1);
		for (int i = 1; i <= N; i++) {
			cin >> v[i];
			// 차수 증가
			in[v[i]]++;
		}
		priority_queue<int, vector<int>, greater<int>> pq;
		for (int i = 1; i <= N; i++) {
			// 시작점
			if (!in[i]) {
				pq.push(i);
				cnt++;
			}
		}
		// priority_queue이든 queue이든 순서가 중요한 것이 아니다.
		// 다만, queue적인 성질은 가지고 있어야 한다. (indegree 때문)
		while (!pq.empty()) {
			int t = pq.top();
			pq.pop();
			// 시작할 차례가 돼 차수를 감소시키고, 차수가 0일 경우는
			if (--in[v[t]] == 0) {
				// 위상 정렬 시작
				pq.push(v[t]);
				// 위상 정렬 시작되는 경우 = 사이클을 못 이루는 경우
				// 위상정렬은 DAG에서만 시행 가능!
				cnt++;
			}
		}
		cout << cnt << "\n";
	}
}