// 211011 #8112 0°ú1-2 Platinum IV
// math, bfs
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
const int MAX = 1000002;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
int t, N, trace[MAX];
char str[MAX];
string s;
vector<int> v;
bool visit[MAX];
void solve(int cur) {
	if (cur == -1)
		return;
	s += str[cur];
	solve(trace[cur]);
}
void bfs(int cur) {
	queue<int> q;
	q.push(1);
	visit[1] = true;
	trace[1] = -1;
	str[1] = '1';
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		if (!x) {
			solve(0);
		}
		for (int i = 0; i < 2; i++) {
			int nx = (x * 10 + i) % N;
			if (!visit[nx]) {
				visit[nx] = true;
				trace[nx] = x;
				str[nx] = (char)(i + '0');
				q.push(nx);
			}
		}
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> t;
	while (t--) {
		cin >> N;
		if (N == 1) {
			cout << 1 << "\n";
			continue;
		}
		fill(visit, visit + MAX, false);
		fill(trace, trace + MAX, -1);
		fill(str, str + MAX, '0');
		s.clear();
		bfs(N);
		reverse(all(s));
		cout << s << "\n";
	}
}