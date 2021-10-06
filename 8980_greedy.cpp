// 211006 #8980 ец╧Х Gold III
// greedy, sort -> as much as possible meeting rooms greedy
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<pi, int> pii;
const int MAX = 2004;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
int N, C, M, ans, d[MAX];
vector<pii> v;
bool cmp(pii p1, pii p2) {
	if (p1.first.second == p2.first.second)
		return p1.first.first < p2.first.first;
	return p1.first.second < p2.first.second;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> C >> M;
	for (int i = 0; i < M; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		v.push_back({ {a,b}, cost });
	}
	sort(all(v), cmp);
	for (int i = 0; i < M; i++) {
		int n1 = v[i].first.first;
		int n2 = v[i].first.second;
		int cost = v[i].second, tmp = 0;
		for (int j = n1; j < n2; j++) {
			tmp = max(tmp, d[j]);
		}
		int ret= max(0, min(cost, C - tmp));
		ans += ret;
		for (int j = n1; j < n2; j++) {
			d[j] += ret;
		}
	}
	cout << ans << "\n";
}