// 210805 #2515 ¿¸Ω√¿Â Gold II
// dp + binary_search
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MAX = 300001;
int N, S, d[MAX];
vector<int> h;
vector<pi> v;
int dp(int cur) {
	if (cur >= N)
		return 0;
	int& ret = d[cur];
	if (ret != -1)
		return ret;
	int idx = lower_bound(all(h), v[cur].first + S) - h.begin();
	ret = max(dp(cur + 1), dp(idx) + v[cur].second);
	return ret;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> S;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i].first >> v[i].second;
		h.push_back(v[i].first);
	}
	sort(all(v));
	sort(all(h));
	memset(d, -1, sizeof(d));
	cout << dp(0) << "\n";
}