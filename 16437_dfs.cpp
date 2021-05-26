// 210526 #16437 양 구출 작전 Gold II
// dfs
// if wolf, ret-=wolf cnt
#include <iostream>
#include <algorithm>
#include <vector>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
const int MAX = 123457;
int N;
pair<char, ll> p[MAX];
vector<int> v[MAX];
bool visit[MAX];
ll dfs(int cur) {
	visit[cur] = true;
	ll ret = 0;
	if (p[cur].first == 'S')
		ret += p[cur].second;
	else
		ret -= p[cur].second;
	for (auto i : v[cur]) {
		if (!visit[i]) {
			ret += dfs(i);
		}
	}
	return max((ll)0, ret);
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 2; i <= N; i++) {
		char ch;
		ll n, u;
		cin >> ch >> n >> u;
		p[i] = { ch, n };
		v[i].push_back(u);
		v[u].push_back(i);
	}
	cout << dfs(1) << "\n";
}