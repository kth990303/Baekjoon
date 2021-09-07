// 210907 #12880 그래프 차이 최소 Platinum IV
// SCC + coordinate_compression + two_pointers
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <stack>
#include <set>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
const int MAX = 51;
const int INF = 150000;
int N, id, d[MAX], m = INF, M = 0;
vector<int> v[MAX], E2;
vector<vector<int>> SCC;
vector<pii> E;
stack<int> s;
bool finished[MAX], visit[MAX][MAX];
int dfs(int x) {
	d[x] = id++;
	s.push(x);

	int parent = d[x];
	for (auto i : v[x]) {
		if (visit[x][i])
			continue;
		if (d[i] == -1)
			parent = min(parent, dfs(i));
		else if (!finished[i])
			parent = min(parent, d[i]);
	}
	if (parent == d[x]) {
		vector<int> scc;
		int prev = -1;
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			prev = t;
			if (t == x)
				break;
		}
		SCC.push_back(scc);
	}
	return parent;
}
bool getScc() {
	id = 0;
	s.empty();
	SCC.clear();
	fill(d, d + N, -1);
	fill(finished, finished + N, false);
	for (int i = 0; i < N; i++) {
		if (d[i] == -1)
			dfs(i);
	}
	return SCC.size() == 1 ? true : false;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int num;
			cin >> num;
			E.push_back({ num, {i, j} });
			E2.push_back(num);
			m = min(m, num);
			M = max(M, num);
		}
	}
	if (N == 1) {
		cout << 0 << "\n";
		return 0;
	}
	sort(all(E));
	sort(all(E2));
	press(E2);
	int s = m, e = m, ans = INF, size = E.size();
	int idx = 0, idx2 = 0, idx3 = 0, idx4 = 0;
	bool newE = true;
	while (s != M) {
		while (newE && idx<size && E[idx].first == e) {
			int n1 = E[idx].second.first;
			int n2 = E[idx].second.second;
			v[n1].push_back(n2);
			idx++;
		}
		while (!newE && idx2<size && E[idx2].first < s) {
			int n1 = E[idx2].second.first;
			int n2 = E[idx2].second.second;
			visit[n1][n2] = true;
			idx2++;
		}
		bool flag = getScc();
		if (e != M && !flag) {
			newE = true;
			e = E2[++idx4];
		}
		else {
			if (flag)
				ans = min(ans, e - s);
			newE = false;
			s = E2[++idx3];			
		}
	}
	cout << ans << "\n";
}