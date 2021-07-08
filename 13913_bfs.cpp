// 210708 #13913 ¼û¹Ù²ÀÁú4 Gold IV
// bfs + trace
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
int N, K, ans;
vector<int> v;
int visit[MAX];
int bfs(int cur) {
	queue<pi> q;
	q.push({ 0, cur });
	visit[cur] = 0;
	while (!q.empty()) {
		int x = q.front().second;
		int time = q.front().first;
		visit[x] = time;
		if (x == K)
			return time;
		q.pop();
		if (x * 2 < MAX && visit[x * 2] == -1) {
			visit[x * 2] = time + 1;
			q.push({ time + 1, x * 2 });
		}
		if (x + 1 < MAX && visit[x + 1] == -1) {
			visit[x + 1] = time + 1;
			q.push({ time + 1, x + 1 });
		}
		if (x >= 1 && visit[x - 1] == -1) {
			visit[x - 1] = time + 1;
			q.push({ time + 1, x - 1 });
		}
	}
}
void trace(int x, int t) {
	v.push_back(x);
	if (!t)
		return;
	if (v.size()<=ans && !(x % 2) && visit[x / 2] == t - 1)
		trace(x / 2, t - 1);
	if (v.size()<=ans && visit[x + 1] == t - 1)
		trace(x + 1, t - 1);
	if (v.size()<=ans && visit[x - 1] == t - 1)
		trace(x - 1, t - 1);
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K;
	fill(visit, visit + MAX, -1);
	ans = bfs(N);
	cout << ans << "\n";
	trace(K, ans);
	for (int i = v.size() - 1; i >= 0; i--)
		cout << v[i] << " ";
}