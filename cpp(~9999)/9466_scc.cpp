// 201225 #9466 텀 프로젝트 Gold IV
// SCC를 구하는 문제. 다만, SCC를 나열할 필요 없어 단순 dfs로도 구현 가능
// SCC 풀이 O(N) : O(V+E)이므로
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
const int MAX = 100001;
using namespace std;
vector<int> v[MAX];
vector<vector<int>> SCC;
int id, d[MAX];
bool finished[MAX];
stack<int> s;
int N, ans;
int dfs(int x) {
	// 여기서는 id는 필요하지 않다.
	// scc 나열을 할 필요가 없으므로
	d[x] = ++id;
	// 스택에 넣어서 scc에 넣어주자
	s.push(x);

	int parent = d[x];
	for (auto i : v[x]) {
		// 아직 방문하지 않았으면
		if (!d[i])
			parent = min(parent, dfs(i));
		// 방문했는데, 이미 완결된 노드가 아니라면
		else if (!finished[i])
			parent = min(parent, d[i]);
	}
	// 사이클에 생성됐다면
	if (parent == d[x]) {
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			// 완결된 노드로 변경
			finished[t] = true;
			if (t == x)
				break;
		}
		// scc사이즈가 1일 경우, 자기 자신이어야만 한다.
		if (scc.size() > 1 || v[scc[0]][0] == scc[0])
			SCC.push_back(scc);
	}
	return parent;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		// 초기화 작업
		for (auto& i : v)
			i.clear();
		SCC.clear();
		id = 0, ans = 0;
		fill(d, d + MAX, 0);
		fill(finished, finished + MAX, false);
		while (!s.empty())
			s.pop();

		cin >> N;
		for (int i = 1; i <= N; i++) {
			int k;
			cin >> k;
			// i번째 애는 k번째랑 팀이 되고 싶어함.
			// 단방향 그래프
			v[i].push_back(k);
		}
		for (int i = 1; i <= N; i++) {
			// 아직 탐색을 안했으면 탐색 시작
			if (!d[i])
				dfs(i);
		}
		// 한 사이클(팀)에 있는 팀원 수 더해주기
		for (int i = 0; i < SCC.size(); i++) {
			ans += SCC[i].size();
		}
		cout << N - ans << "\n";
	}
}