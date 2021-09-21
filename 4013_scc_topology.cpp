// 210921 #4013 ATM Platinum II
// SCC + topology_sort
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
const int MAX = 500001;
const int INF = 0x3f3f3f3f;
int N, M, d[MAX], id, sccNum[MAX], w[MAX], S, cnt;
int in[MAX], sccW[MAX], sccMaxW[MAX];
vector<int> v[MAX], c[MAX];
vector<vector<int>> SCC;
bool finished[MAX], restaurant[MAX], sccRes[MAX], can[MAX];
stack<int> s;
int dfs(int x) {
	d[x] = id++;
	s.push(x);

	int parent = d[x];
	for (auto i : v[x]) {
		if (d[i] == -1)
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
			sccNum[t] = SCC.size();
			if (t == x)
				break;
		}
		SCC.push_back(scc);
	}
	return parent;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		v[a].push_back(b);
	}
	fill(d, d + N, -1);
	// O(N)
	for (int i = 0; i < N; i++) {
		if (d[i] == -1)
			dfs(i);
	}
	for (int i = 0; i < N; i++) {
		cin >> w[i];
	}
	cin >> S >> cnt;
	S--;
	S = sccNum[S];
	for (int i = 0; i < cnt; i++) {
		int n;
		cin >> n;
		restaurant[--n] = true;
	}
	// scc ordering
	for (int i = 0; i < N; i++) {
		sccW[sccNum[i]] += w[i];
		if (restaurant[i])
			sccRes[sccNum[i]] = true;
		for (auto j : v[i]) {
			if (sccNum[j] != sccNum[i]) {
				c[sccNum[i]].push_back(sccNum[j]);
				in[sccNum[j]]++;
			}
		}
	}
	queue<int> q;
	for (int i = 0; i < SCC.size(); i++) {
		sccMaxW[i] = sccW[i];
		if (!in[i])
			q.push(i);
	}
	can[S] = true;
	int ans = 0;
	// O(N+M)
	// if many early queue elements, can exist that we can't go points
	// so make can[MAX] array
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto i : c[cur]) {
			if (can[cur]) {
				sccMaxW[i] = max(sccMaxW[i], sccMaxW[cur] + sccW[i]);
				can[i] = true;
			}
			if (--in[i]==0) {
				q.push(i);
			}
		}
	}
	for (int i = 0; i < SCC.size(); i++) {
		if (can[i] && sccRes[i])
			ans = max(ans, sccMaxW[i]);
	}
	cout << ans << "\n";
}