// 210212 #2668 숫자고르기 Gold V
// if cycle -> check vector v1, v2 same
// if same -> include answer
// I think it's not the best solution
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 101;
int N, a[MAX];
bool visit[MAX], finished[MAX];
vector<int> v1, v2;
// if same?
bool check() {
	if (v1.size() != v2.size())
		return false;
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	for (int i = 0; i < v1.size(); i++) {
		if (v1[i] != v2[i])
			return false;
	}
	return true;
}
// use dfs to check the cycle
int dfs(int cur) {
	visit[cur] = true;
	v1.push_back(cur);
	if (!visit[a[cur]]) {
		visit[a[cur]] = true;
		v2.push_back(a[cur]);
		return dfs(a[cur]);
	}
	else if (!finished[a[cur]]) {
		// if reverse E
		v2.push_back(a[cur]);
		// check cycle
		if (check()) {
			for (auto i : v1) {
				finished[i] = true;
			}
			return v1.size();
		}
		else
			return 0;
	}
	return 0;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		ans += dfs(i);
		// init
		v1.clear();
		v2.clear();
		fill(visit, visit + N + 1, false);
	}
	cout << ans << "\n";
	for (int i = 1; i <= N; i++) {
		if (finished[i])
			cout << i << "\n";
	}
}