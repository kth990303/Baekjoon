// 210207 #1374 강의실 Gold IV
// Greedy like #1689 겹치는 선분
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100001;
vector<pair<int, int>> v;
int N, ans;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	v.resize(N * 2);
	for (int i = 0; i < N; i++) {
		int num;
		cin >> num >> v[2 * i].first >> v[2 * i + 1].first;
		v[2 * i].second = 1;
		v[2 * i + 1].second = -1;
	}
	sort(v.begin(), v.end());
	int cnt = 0;
	for (int i = 0; i < v.size(); i++) {
		cnt += v[i].second;
		ans = max(ans, cnt);
	}
	cout << ans << "\n";
}