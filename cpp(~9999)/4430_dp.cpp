// 210530 #4430 Is Bigger Smarter? Gold V
// dp_trace
// Nobody solves this problem. I'm first solver~
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MAX = 1001;
const int MAX_C = 10001;
const int INF = 1e9 + 7;
vector<pair<int, pi>> v;
vector<int> res;
int N, d[MAX], trace[MAX];
bool cmp(pair<int, pi> p1, pair<int, pi> p2) {
	if (p1.second.first == p2.second.first)
		return p1.second.second > p2.second.second;
	return p1.second.first < p2.second.first;
}
int dp(int cur) {
	if (cur >= N)
		return 0;
	int& ret = d[cur];
	if (ret != -1)
		return ret;
	ret = 1;
	for (int i = cur + 1; i < N; i++) {
		if (v[cur].second.first<v[i].second.first
			&& v[cur].second.second > v[i].second.second) {
			ret = max(ret, dp(i) + 1);
		}
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int w, s;
	while (cin >> w >> s && w && s) {
		v.push_back({ ++N, { w, s } });
	}
	sort(all(v), cmp);
	memset(d, -1, sizeof(d));
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans = max(ans, dp(i));
	}
	cout << ans << "\n";
	int k = ans;
	for (int i = 0; i < N; i++) {
		if (k == d[i]) {
			cout << v[i].first << "\n";
			k--;
		}
	}
}