// 200826 #2207 Platinum IV
// 가위바위보 룰을 바꿔버려서 2-SAT로
// 둘 중 하나라도 맞추면 살고
// 모두가 살 수 있도록 -> 2-SAT
/*
2 1
1 1
-1 -1
ans: OTL
*/
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, id, d[20002], ans[20002];
bool finished[20002];
vector<int> v[20002];
vector<vector<int>> SCC;
stack<int> s;
int f(int a) {
	return a > M ? a - M : a + M;
}
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
			finished[t] = true;
			scc.push_back(t);
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
	while (N--) {
		int a, b;
		cin >> a >> b;
		if (a < 0) a = -a + M;
		if (b < 0)b = -b + M;
		v[f(a)].push_back(b);
		v[f(b)].push_back(a);
	}
	for (int i = 1; i <= 2*M; i++) {
		if (!d[i])
			dfs(i);
	}
	for (int i = 1; i <= M; i++) {
		if (ans[i] == ans[i + M]) {
			cout << "OTL";
			return 0;
		}
	}
	cout << "^_^";
}