// 210301 #2655 가장높은탑쌓기 Gold IV
// dp_trace
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 101;
typedef pair<pair<int, int>, pair<int, int>> pii;
vector<pii> v;
vector<int> v2;
int N, d[MAX];
int dp(int cur) {
	int& ret = d[cur];
	if (ret != -1)
		return ret;
	ret = 0;
	for (int i = cur + 1; i <= N; i++) {
		// search all cases
		if (v[cur].second.second > v[i].second.second) {
			ret = max(ret, dp(i));
		}
	}
	// then add v[cur]'s height
	ret += v[cur].second.first;
	return ret;
}
// #2655 is difficult because of trace
void trace(int cur, int h) {
	// don't push_back cur. order is important
	v2.push_back(v[cur].first.second);
	for (int i = cur + 1; i <= N; i++) {
		if (dp(i) == h) {
			trace(i, h - v[i].second.first);
			return;
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	v.resize(N + 1);
	for (int i = 1; i <= N; i++) {
		cin >> v[i].first.first >> v[i].second.first >> v[i].second.second;
		v[i].first.second = i;
	}
	sort(v.begin() + 1, v.end(), greater<pii>());
	int maxH = 0, idx = 0;
	fill(d, d + MAX, -1);
	for (int i = 1; i <= N; i++) {
		if (maxH < dp(i)) {
			idx = i;
			maxH = dp(i);
		}
	}
	trace(idx, maxH - v[idx].second.first);
	cout << v2.size() << "\n";
	for (int i = v2.size() - 1; i >= 0; i--) {
		cout << v2[i] << "\n";
	}
}