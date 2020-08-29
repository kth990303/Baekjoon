// 200829 #4013 ATM Platinum II
// SCC 후, 조건 고려하여 SCC끼리 위상정렬 다 해보는 문제
// 호흡이 길고 꽤나 어려움
// 2시간이 증발함
// 다행히 로직은 처음부터 잘 짰으나, 구현이 잘못됨
// 라이(kks227)님 블로그 참고함
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
const int MAX = 500001;
const int DNF = 1000000007;
using namespace std;
int N, M, id, d[MAX], w[MAX], sccNum[MAX];
bool finished[MAX], isEat[MAX];
vector<int> v[MAX];
vector<vector<int>> SCC;
stack<int> s;
// 위상정렬 세팅
int sccW[MAX], in[MAX];	// scc 돈 합, indegree
vector<int> adj[MAX];	
bool sccHasEat[MAX];
bool can[MAX];
int ans[MAX];
int dfs(int x) {
	d[x] = ++id;
	s.push(x);
	
	int parent = d[x];
	for (auto i : v[x]) {
		if (!d[i])
			parent = min(parent, dfs(i));
		else if (!finished[i])
			parent = min(parent, d[i]);
	}
	if (parent == d[x]) {
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			sccNum[t] = SCC.size() + 1;
			if (t == x)
				break;
		}
		SCC.push_back(scc);
	}
	return parent;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	while (M--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	// SCC 만들기
	for (int i = 1; i <= N; i++) {
		if (!d[i])
			dfs(i);
	}
	// 돈 정보 입력
	for (int i = 1; i <= N; i++) {
		cin >> w[i];
	}
	int s, k;
	cin >> s >> k;
	// 레스토랑 여부 입력 (예제의 경우 전부 보유)
	for (int i = 1; i <= k; i++) {
		int num;
		cin >> num;
		isEat[num] = true;
	}
	// 정보 입력 끝.
	for (int i = 1; i <= N; i++) {
		sccW[sccNum[i]] += w[i];
		// scc가 출발 지점을 가지고 있는가?
		if (s == i)
			s = sccNum[i];
		// scc가 레스토랑을 가지고 있는가?
		if (isEat[i])
			sccHasEat[sccNum[i]] = true;

		for (int next : v[i]) {
			if (sccNum[next] == sccNum[i])
				continue;
			// scc가 다른 경우 인접 scc 넣어줌
			adj[sccNum[i]].push_back(sccNum[next]);
			// 위상정렬을 위한 행위
			in[sccNum[next]]++;
		}
	}
	int res = 0;
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		w[i] = sccW[i];	// scc 액수만큼 초기화
		if (i == s)
			can[i] = true;
		if (!in[i])
			q.push(i);
	}
	// SCC 끼리 위상정렬
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto i : adj[x]) {
			if (can[x]) {
				w[i] = max(w[i], w[x] + sccW[i]);
				can[i] = true;
			}
			in[i]--;
			if (!in[i])
				q.push(i);
		}
	}
	for (int i = 1; i <= SCC.size(); i++) {
		if (sccHasEat[i] && can[i])
			res = max(res, w[i]);
	}
	cout << res << "\n";
}