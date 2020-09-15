// 200915 #16938 캠프 준비 Gold IV
// 알고리즘 강의 중급 2/3 문제
// 조합론, 백트래킹
// 시간복잡도: O(2^N)
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int INF = 1000000007;
const int MAX = 16;
int N, L, R, X, ans, a[MAX];
vector<int> v;
bool visit[MAX];
bool check() {
	if (v.size() < 2)
		return false;
	int sum = 0, max_num = 0, min_num = INF;
	for (int i = 0; i < v.size(); i++) {
		max_num = max(max_num, v[i]);
		min_num = min(min_num, v[i]);
		sum += v[i];
	}
	if (sum<L || sum>R)
		return false;
	if (max_num - min_num < X)
		return false;
	return true;
}
int dfs(int cur) {
	if (cur == N) {
		if (check())
			return 1;
		else
			return 0;
	}
	visit[cur] = true;
	v.push_back(a[cur]);
	int cnt1 = dfs(cur + 1);
	v.pop_back();
	visit[cur] = false;
	int cnt2 = dfs(cur + 1);
	return cnt1 + cnt2;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> L >> R >> X;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	ans = dfs(0);
	cout << ans << "\n";
}