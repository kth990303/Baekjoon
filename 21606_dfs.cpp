// 210918 #21606 아침산책 Gold III
// dfs O(N)
// if outside, think of cluster -> inside cnt*(cnt-1)
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
const int MAX = 200001;
const int MOD = 1e9 + 7;
ll N, ans;
string s;
vector<int> v[MAX];
bool visit[MAX];
ll dfs(int cur) {
	ll ret = 0;
	visit[cur] = true;
	for (auto i : v[cur]) {
		if (!visit[i]) {
			if (s[i] == '0')
				ret += dfs(i);
			else
				ret++;
		}
	}
	return ret;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> s;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 0; i < N; i++) {
		if (s[i] == '1') {
			for (auto j : v[i])
				ans += s[j] == '1';
		}
		else {
			if (visit[i])
				continue;
			ll ret = dfs(i);
			ans += ret * (ret - 1);
		}
	}
	cout << ans << "\n";
}