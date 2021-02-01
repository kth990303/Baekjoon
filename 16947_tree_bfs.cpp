// 210201 #16947 서울 지하철 2호선 Gold III
// Tree cycle -> indegree + bfs
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 3001;
int N, in[MAX];
vector<int> v[MAX];
bool visit[MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		in[a]++;
		in[b]++;
	}
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (in[i] == 1)
			q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		in[cur]--;
		for (auto i : v[cur]) {
			if (!in[i])
				continue;
			// if cycle, in[i]>1
			if (--in[i] == 1) {
				q.push(i);
			}
		}
	}
	vector<int> ans;
	ans.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		if (in[i]) {
			ans[i] = 0;
			visit[i] = true;
			q.push(i);
		}
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto i : v[cur]) {
			if (!visit[i]) {
				ans[i] = ans[cur] + 1;
				visit[i] = true;
				q.push(i);
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		cout << ans[i] << " ";
	}
}