// 210102 #16964 DFS 스페셜 저지 Gold V
// Tree can have 2 or more leaves.
#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;
const int MAX = 100001;
vector<int> v[MAX];
// Create a new (order of visits)
int N, time, d[MAX], order[MAX];
bool visit[MAX];
// order by visit asc.
bool cmp(int a, int b) {
	return order[a] < order[b];
}
bool dfs(int cur) {
	if (cur != d[time]) {
		cout << 0 << "\n";
		exit(0);	// exit
	}
	visit[cur] = true;
	sort(v[cur].begin(), v[cur].end(), cmp);
	for (auto i : v[cur]) {
		if (!visit[i]) {
			time++;
			dfs(i);
		}
	}
	return true;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < N; i++) {
		cin >> d[i];
		order[d[i]] = i + 1;
	}
	cout << dfs(1) << "\n";
	
}