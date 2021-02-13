// 210213 #10265 MT Platinum IV
// dfs_cycle + knapsack dp
// another solution: scc
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;
const int MAX = 1001;
int N, K, in[MAX], dt[MAX][MAX];
vector<int> v[MAX], trace[MAX];
vector<vector<int>> ans;
vector<pair<int, int>> list;
bool visit[MAX];
// knapsack dp
int dp(int cur, int num) {
	int& ret = dt[cur][num];
	if (ret != -1)
		return ret;
	if (cur >= list.size())
		return ret = 0;
	ret = dp(cur + 1, num);
	for (int i = list[cur].first; i <= list[cur].second; i++) {
		if (num + i <= K)
			ret = max(ret, dp(cur + 1, num + i) + i);
	}
	return ret;
}
// check nodes that make up the cycle
void dfs(int cur, vector<int>& tmp) {
	if (visit[cur]) {
		return;
	}
	visit[cur] = true;
	tmp.push_back(cur);
	for (auto i : v[cur]) {
		if (in[i] == 1)
			dfs(i, tmp);
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;
		v[i].push_back(n);
		// check component node
		trace[n].push_back(i);
		in[n]++;
	}
	queue<int> q;
	// check cycle
	for (int i = 1; i <= N; i++) {
		if (!in[i])
			q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		in[cur]--;
		for (auto i : v[cur]) {
			if (!(--in[i])) {
				q.push(i);
			}
		}
	}
	// if cycle, these members are necessary
	for (int i = 1; i <= N; i++) {
		if (in[i] == 1 && !visit[i]) {
			vector<int> tmp;
			dfs(i, tmp);
			ans.push_back(tmp);
			list.push_back({ tmp.size(), tmp.size() });
		}
	}
	for (int i = 0; i < ans.size(); i++) {
		// necessary member
		int cnt = list[i].second;
		for (auto j : ans[i]) {
			q.push(j);
			// check uncertain number
			while (!q.empty()) {
				int cur = q.front();
				q.pop();
				for (auto k : trace[cur]) {
					if (!visit[k]) {
						cnt++;
						q.push(k);
					}
				}
			}
		}
		// necessary member + uncertain number
		list[i].second = cnt;
	}
	// max knapsack dp
	memset(dt, -1, sizeof(dt));
	cout << dp(0, 0) << "\n";
}