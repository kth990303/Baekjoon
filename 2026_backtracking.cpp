// 210414 #2026 ¼ÒÇ³ Gold III
// backtracking
#include <iostream>
#include <algorithm>
#include <vector>
#define all(v) v.begin(), v.end()
using namespace std;
const int MAX = 901;
vector<int> ans;
int K, N, F;
bool visit[MAX][MAX];
void solve(int cur) {
	if (ans.size() == K) {
		for (auto i : ans) {
			cout << i << "\n";
		}
		exit(0);
	}
	for (auto i : ans) {
		if (cur != i && !visit[cur][i]) {
			return;
		}
	}
	for (int i = cur + 1; i <= N; i++) {
		// all check
		bool flag = true;
		for (auto j : ans) {
			if (!visit[i][j]) {
				flag = false;
				break;
			}
		}
		if (flag && visit[cur][i]) {
			ans.push_back(i);
			solve(i);
			ans.pop_back();
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> K >> N >> F;
	while (F--) {
		int a, b;
		cin >> a >> b;
		visit[a][b] = visit[b][a] = true;
	}
	for (int i = 1; i <= N; i++) {
		ans.push_back(i);
		solve(i);
		ans.pop_back();
	}
	cout << -1 << "\n";
}