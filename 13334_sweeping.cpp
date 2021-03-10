// 210311 #13334 Ã¶·Î Gold II
// Sweeping, why this question Gold II?
// I think it's Gold III
// O(NlgN)
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int MAX = 100001;
int N, D, ans;
vector<pair<int, int>> v;
// greedy
bool cmp(pair<int, int> p1, pair<int, int> p2) {
	if (p1.second == p2.second)
		return p1.first < p2.first;
	return p1.second < p2.second;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
		if (v[i].first > v[i].second)
			swap(v[i].first, v[i].second);
	}
	cin >> D;
	sort(v.begin(), v.end(), cmp);
	priority_queue<int, vector<int>, greater<int>> pq;
	int len = 0, cnt = 0;
	for (int i = 0; i < N; i++) {
		if (v[i].second - v[i].first > D)
			continue;
		pq.push(v[i].first);
		len = v[i].second - pq.top();
		while (1) {
			if (!pq.empty() && len > D) {
				pq.pop();
				cnt--;
				len = v[i].second - pq.top();
			}
			else {
				cnt++;
				break;
			}
		}
		ans = max(ans, cnt);
	}
	cout << ans << "\n";
}