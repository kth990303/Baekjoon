// 210505 #19538 ·ç¸Ó Gold IV
// if time==0: push queue
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 200001;
vector<int> v[MAX];
int N, M, ans[MAX], truth[MAX];
queue<pair<int, int>> q;
void bfs() {
	while (!q.empty()) {
		int cur = q.front().first;
		int time = q.front().second;
		ans[cur] = time;
		q.pop();
		for (auto i : v[cur]) {
			if (ans[i] >= 0 || truth[i] >= (double)v[i].size() / 2)
				continue;
			if (ans[cur] == time)
				truth[i]++;
			if (truth[i] >= (double)v[i].size() / 2) {
				truth[cur]++;
				q.push({ i, time + 1 });
			}
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		ans[i] = -1;
		int k;
		while (cin >> k && k) {
			v[i].push_back(k);
		}
	}
	cin >> M;
	while (M--) {
		int k;
		cin >> k;
		ans[k] = 0;
		q.push({ k, 0 });
	}
	bfs();
	for (int i = 1; i <= N; i++) {
		cout << ans[i] << " ";
	}
}