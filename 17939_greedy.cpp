// 210724 #17939 Gazzzua Silver I
// greedy + sort
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 100001;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
int N, a[MAX], ans;
vector<pi> v;
bool visit[MAX];
bool cmp(pi p1, pi p2) {
	if (p1.first == p2.first)
		return p1.second < p2.second;
	return p1.first > p2.first;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		v.push_back({ a[i], i });
	}
	sort(all(v), cmp);
	int cnt = 0, i = 0;
	while (cnt < N) {
		int cur = v[i].second;
		if (visit[cur]) {
			i++;
			continue;
		}
		int n = v[i].first;
		for (int j = 0; j <= cur; j++) {
			if (visit[j])
				continue;
			ans += (n - a[j]);
			visit[j] = true;
			cnt++;
		}
		i++;
	}
	cout << ans << "\n";
}