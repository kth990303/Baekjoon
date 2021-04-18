// 210418 #1949 우수 마을 Gold I
// make child tree to visit more then once, but not parent node
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const int MAX = 10001;
int N, a[MAX], d[MAX][2];
bool visit[MAX];
vector<int> v[MAX], c[MAX];
void check(int cur) {
	visit[cur] = true;
	for (auto i : v[cur]) {
		if (!visit[i]) {
			visit[i] = true;
			c[cur].push_back(i);
			check(i);
		}
	}
}
int dp(int cur, bool flag) {
	int& ret = d[cur][flag];
	if (ret != -1)
		return ret;
	ret = 0;
	int tmp = 0;
	for (auto i : c[cur]) {
		// we need max ret,
		// so we don't need check false -> false -> false
		tmp = dp(i, false);
		if (!flag)
			tmp = max(tmp, dp(i, true));
		ret += tmp;
	}
	if (flag)
		ret += a[cur];
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < N - 1; i++) {
		int x, y;
		cin >> x >> y;
		v[x].push_back(y);
		v[y].push_back(x);
	}
	check(1);
	memset(d, -1, sizeof(d));
	int ans = dp(1, false);
	ans = max(ans, dp(1, true));
	cout << ans << "\n";
}