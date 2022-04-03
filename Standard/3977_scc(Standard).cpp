// 220403 #3977 축구전술 Platinum IV
// 0-based SCC Standard Solution O(M)
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#define sz(v) (int)(v).size()
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
const int MAX = 1e5 + 3;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e16;
const int MOD = 1e9 + 7;
vector<int> v[MAX];
vector<vector<int>> SCC;
stack<int> s;
int t, N, M, d[MAX], id, sccNum[MAX], in[MAX];
bool finished[MAX];
int dfs(int x) {
	int parent = d[x] = id++;
	s.push(x);
	for (auto i : v[x]) {
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
			sccNum[t] = SCC.size();
			finished[t] = true;
			prev = t;
			if (t == x)
				break;
		}
		SCC.push_back(scc);
	}
	return parent;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> t;
	while (t--) {
		memset(finished, false, sizeof(finished));
		fill(d, d + MAX, -1);
		fill(sccNum, sccNum + MAX, -1);
		fill(in, in + MAX, 0);
		for (auto& i : v)i.clear();
		SCC.clear();
		id = 0;
		cin >> N >> M;
		while (M--) {
			int n1, n2;
			cin >> n1 >> n2;
			v[n1].push_back(n2);
		}
		for (int i = 0; i < N; i++) {
			if (d[i] == -1)
				dfs(i);
		}
		for (int i = 0; i < N; i++) {
			for (int j : v[i]) {
				if (sccNum[i] != sccNum[j])
					in[sccNum[j]]++;
			}
		}
		bool flag = false;
		vector<int> ans;
		for (int i = 0; i < sz(SCC); i++) {
			if (!in[i]) {
				if (flag) {
					flag = false;
					break;
				}
				flag = true;
				for (int j : SCC[i])ans.push_back(j);
			}
		}
		sort(all(ans));
		if (!flag)cout << "Confused\n";
		else for (int i : ans)cout << i << "\n";
	}
}