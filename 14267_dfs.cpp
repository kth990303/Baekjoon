// 210615 #14267 회사문화1 Gold IV
// dfs
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <cstring>
#include <map>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 100001;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int N, M, p[MAX], d[MAX];
vector<int> v[MAX];
bool visit[MAX];
void dfs(int cur, int w) {
	visit[cur] = true;
	d[cur] = w;
	for (auto i : v[cur]) {
		if (!visit[i]) {
			dfs(i, w + p[i]);
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int n;
		cin >> n;
		if (i == 1)
			continue;
		v[n].push_back(i);
	}
	while (M--) {
		int i, w;
		cin >> i >> w;
		p[i] += w;
	}
	dfs(1, 0);
	for (int i = 1; i <= N; i++) {
		cout << d[i] << " ";
	}
}