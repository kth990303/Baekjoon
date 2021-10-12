// 211012 #14168 Cow Checklist Gold I
// USACO 2016 Dec Gold
// dp
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
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
const int MAX = 1011;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e16;
const ll MOD = 1e9 + 7;
ll H, G, d[MAX][MAX][2];
vector<pl> h, g;
ll dis(pl p1, pl p2) {
	return (p1.first - p2.first) * (p1.first - p2.first)
		+ (p1.second - p2.second) * (p1.second - p2.second);
}
ll dp(int curh, int curg, int flag) {
	if (curh == H - 1 && curg == G - 1)
		return !flag ? 0 : LNF;
	// cannot -1 index
	ll& ret = d[curh][curg+1][flag];
	if (ret != -1)
		return ret;
	ret = LNF;
	if (curh < H-1) {
		!flag ? ret = min(ret, dp(curh + 1, curg, 0) + dis(h[curh], h[curh + 1]))
			: ret = min(ret, dp(curh+1, curg, 0) + dis(g[curg], h[curh + 1]));
	}
	if (curg < G-1) {
		!flag ? ret = min(ret, dp(curh, curg+1, 1) + dis(h[curh], g[curg + 1]))
			: ret = min(ret, dp(curh, curg + 1, 1) + dis(g[curg], g[curg + 1]));
	}
	return ret;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> H >> G;
	h.resize(H);
	g.resize(G);
	for (int i = 0; i < H; i++)
		cin >> h[i].first >> h[i].second;
	for (int i = 0; i < G; i++)
		cin >> g[i].first >> g[i].second;
	memset(d, -1, sizeof(d));
	// if dp(0,0,0), then you already visit g[0]
	cout << dp(0, -1, 0) << "\n";
}