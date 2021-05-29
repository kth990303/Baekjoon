// 210529 #14433 한조 대기중 Platinum V
// bipartite_matching
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
const int MAX = 301;
int N, M, K1, K2, d[MAX];
vector<int> v1[MAX], v2[MAX];
bool used[MAX];
bool dfs1(int cur) {
	for (auto i : v1[cur]) {
		if (used[i])
			continue;
		used[i] = true;
		if (!d[i] || dfs1(d[i])) {
			d[i] = cur;
			return true;
		}
	}
	return false;
}
bool dfs2(int cur) {
	for (auto i : v2[cur]) {
		if (used[i])
			continue;
		used[i] = true;
		if (!d[i] || dfs2(d[i])) {
			d[i] = cur;
			return true;
		}
	}
	return false;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K1 >> K2;
	while (K1--) {
		int a, b;
		cin >> a >> b;
		v1[a].push_back(b);
	}
	while (K2--) {
		int a, b;
		cin >> a >> b;
		v2[a].push_back(b);
	}
	int ans1 = 0, ans2 = 0;
	for (int i = 1; i <= N; i++) {
		fill(used, used + MAX, false);
		if (dfs1(i))
			ans1++;
	}
	fill(d, d + MAX, false);
	for (int i = 1; i <= N; i++) {
		fill(used, used + MAX, false);
		if (dfs2(i))
			ans2++;
	}
	if (ans1 >= ans2)
		cout << "그만 알아보자\n";
	else
		cout << "네 다음 힐딱이\n";
}