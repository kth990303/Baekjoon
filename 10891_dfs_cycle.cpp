// 210918 #10891 Cactus? Not Cactus? Platinum III
// dfs spanning tree O(N+M), check same or not same cycle
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
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MAX = 100001;
const int MOD = 1e9 + 7;
int N, M, in[MAX], out[MAX], d[MAX], id;
vector<int> v[MAX];
int dfs(int cur, int prev = -1) {
	d[cur] = id++;
	for (auto i : v[cur]) {
		if (i == prev)
			continue;
		if (d[i] == -1)
			// same cycle
			in[cur] += dfs(i, cur);
		// already visit, but later visit, it's not cycle
		else if (d[i] > d[cur])
			out[cur]++;
		// already visit, and before visit, it's same cycle
		else if (d[i] < d[cur])
			in[cur]++;
	}
	if (in[cur] >= 2) {
		cout << "Not cactus\n";
		exit(0);
	}
	return in[cur] - out[cur];
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	fill(d, d + N, -1);
	dfs(0);
	cout << "Cactus" << "\n";
}