#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <cstring>
using namespace std;
const int MAX = 10001;
int N, M, S, T, num;
int id, finished[MAX], d[MAX], in[MAX], sccNum[MAX];
vector<int> v[MAX];
vector<int> SCC[MAX];
vector<int> inScc[MAX];
stack<int> s;
bool visit[MAX];
int dp[MAX];
int dfs(int x) {
	d[x] = ++id;
	s.push(x);

	int p = d[x];
	for (auto i : v[x]) {
		if (!d[i])
			p = min(p, dfs(i));
		else if (!finished[i])
			p = min(p, d[i]);
	}
	if (p == d[x]) {
		vector<int> scc;
		int prev = -1;
		++num;
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			prev = t;
			sccNum[t] = num;
			if (t == x)
				break;
		}
		SCC[num] = scc;
	}
	return p;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M >> S >> T;
	for (int i = 0; i < M; i++) {
		int s, e;
		cin >> s >> e;
		v[s].push_back(e);
	}
	for (int i = 1; i <= N; i++) {
		if (!d[i])
			dfs(i);
	}
	for (int i = 1; i <= N; i++) {
		for (auto j : v[i]) {
			if (sccNum[i] != sccNum[j]) {
				inScc[sccNum[i]].push_back(sccNum[j]);
				in[sccNum[j]]++;
			}
		}
	}
	int ans = 0;
	queue<int> q;
	visit[sccNum[S]] = true;
	dp[sccNum[S]] = SCC[sccNum[S]].size();
	for (int i = 1; i <= num; i++) {
		dp[i] = SCC[i].size();
		if (!in[i])
			q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto i : inScc[cur]) {
			if (visit[cur]) {
				visit[i] = true;
				dp[i] = max(dp[i], dp[cur] + (int)SCC[i].size());
			}
			if (--in[i] == 0)
				q.push(i);
		}
	}
	if (!visit[sccNum[T]])
		cout << 0 << "\n";
	else
		cout << dp[sccNum[T]] << "\n";
}