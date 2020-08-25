// 200826 2-SAT Algorithm Platinum IV
// SCC + 이산수학 명제와 논리
// 앞으로 2-SAT는 이방법 대로 간다
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, id, d[20002], ans[20002];
vector<int> v[20002];
vector<vector<int>> SCC;
bool finished[20002];
stack<int> s;
int f(int a) {
	// f 가 하는 일:
	// not(음수): -1~-4 -> 음수를 참으로 만들면 절댓값
	// (양수): 1~4 -> 양수를 거짓으로 만들면 N보다 크게
	// 결과: ~a: 1234 a: 5678
	return a > N ? a - N : a + N;
}
int dfs(int x) {
	d[x] = ++id;
	s.push(x);

	int parent = d[x];
	for (auto i : v[x]) {
		// 아직 dfs를 거쳐 확인하지 않았으면
		if (!d[i])
			parent = min(parent, dfs(i));
		// 아직 scc에 포함이 안됐으면
		else if (!finished[i])
			parent = min(parent, d[i]);
	}
	// dfs했더니 부모를 만나 scc가 이뤄진다면
	if (parent == d[x]) {
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			// 까먹지말고 scc에 포함 완료해주자
			finished[t] = true;
			// scc Num은 1부터
			ans[t] = SCC.size() + 1;
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
		// not 일 경우 N+1 ~ N+N
		if (a < 0)
			a = -a + N;
		if (b < 0)
			b = -b + N;
		// f가 있는 이유: not 때문에
		v[f(a)].push_back(b); // ~A -> B 
		v[f(b)].push_back(a); // ~B -> A
	}
	// not 까지 2*N개
	// 그래프로 모델링해주자
	for (int i = 1; i <= 2 * N; i++) {
		if (!d[i])
			dfs(i);
	}
	// 같은 SCC에 
	// ~A -> A 같은 모순이 존재한다면,
	for (int i = 1; i <= N; i++) {
		if (ans[i] == ans[i + N]) {
			cout << "0";
			return 0;
		}
	}
	cout << "1";
}