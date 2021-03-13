// 210313 #1577 도로의 개수 Gold IV
// 무난한 dp
#include <iostream>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;
typedef long long ll;
const int MAX = 101;
ll N, M, K, d[MAX][MAX];
vector<pair<pair<int, int>, pair<int, int>>> v;
ll dp(int y, int x) {
	ll& ret = d[y][x];
	if (ret != -1)
		return ret;
	if (y == M && x == N)
		return ret = 1;
	ret = 0;
	bool flag1 = false, flag2 = false;
	if (y + 1 <= M) {
		for (int i = 0; i < K; i++) {
			if (y == v[i].first.second && x == v[i].first.first
				&& y + 1 == v[i].second.second) {
				flag1 = true;
				break;
			}
		}
		if (!flag1)
			ret += dp(y + 1, x);
	}
	if (x + 1 <= N) {
		for (int i = 0; i < K; i++) {
			if (y == v[i].first.second && x == v[i].first.first
				&& x + 1 == v[i].second.first) {
				flag2 = true;
				break;
			}
		}
		if (!flag2)
			ret += dp(y, x + 1);
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M >> K;
	v.resize(K);
	for (int i = 0; i < K; i++) {
		cin >> v[i].first.first >> v[i].first.second
			>> v[i].second.first >> v[i].second.second;
		if (v[i].first.first > v[i].second.first)
			swap(v[i].first.first, v[i].second.first);
		if (v[i].first.second > v[i].second.second)
			swap(v[i].first.second, v[i].second.second);
	}
	memset(d, -1, sizeof(d));
	cout << dp(0, 0) << "\n";
}