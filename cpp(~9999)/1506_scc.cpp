// 211102 #1506 °æÂû¼­ Platinum V
// Standard scc O(N+M)
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
const int MAX = 111;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e16;
const int MOD = 1e9 + 7;
int N, w[MAX], d[MAX], p[MAX], id, ans;
vector<int> v[MAX];
vector<vector<int>> SCC;
bool finished[MAX];
stack<int> S;
int dfs(int x) {
	d[x] = id++;
	S.push(x);
	int parent = d[x];
	for (auto i : v[x]) {
		if (d[i] == -1)
			parent = min(parent, dfs(i));
		else if (!finished[i])
			parent = min(parent, d[i]);
	}
	if (parent == d[x]) {
		vector<int> scc;
		int prev = -1, cost = INF;
		while (1) {
			int t = S.top();
			S.pop();
			scc.push_back(t);
			finished[t] = true;
			cost = min(cost, w[t]);
			prev = t;
			if (t == x)
				break;
		}
		SCC.push_back(scc);
		ans += cost;
	}
	return parent;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> w[i];
	}
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			if (s[j] == '1') {
				v[i].push_back(j);
			}
		}
	}
	fill(d, d + MAX, -1);
	for (int i = 0; i < N; i++) {
		if (d[i] == -1)
			dfs(i);
	}
	cout << ans << "\n";
}