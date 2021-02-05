// 210205 #1689 °ãÄ¡´Â ¼±ºÐ Gold III
// greedy + prefix_sum
// sweeping? maximum 1e9 -> change point cnt
// start : cnt++ , end: cnt--
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 1000001;
int N, ans;
vector<int> s, e;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	s.resize(N);
	e.resize(N);
	vector<pair<int, int>> res(2 * N);
	for (int i = 0; i < N; i++) {
		cin >> s[i] >> e[i];
		res.push_back({ s[i], 1 });
		res.push_back({ e[i], -1 });
	}
	sort(res.begin(), res.end());
	int cnt = 0;
	for (int i = 0; i < res.size(); i++) {
		cnt += res[i].second;
		ans = max(ans, cnt);
	}
	cout << ans << "\n";
}