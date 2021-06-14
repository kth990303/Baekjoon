// 210614 #21278 호석이 두마리 치킨 Gold V
// floyd
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
const int MAX = 101;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int N, M, ans = INF, A, B, d[MAX][MAX];
vector<pi> res;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	memset(d, INF, sizeof(d));
	for (int i = 0; i < N; i++) {
		d[i][i] = 0;
	}
	while (M--) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		d[a][b] = 1;
		d[b][a] = 1;
	}
	for (int k = 0; k < N; k++) {
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			int ret = 0;
			for (int k = 0; k < N; k++) {
				if (k == i || k == j)
					continue;
				ret += min(d[k][i], d[k][j]);
			}
			ret *= 2;
			if (ret == ans) {
				res.push_back({ i, j });
			}
			else if (ret < ans) {
				res.clear();
				ans = ret;
				res.push_back({ i, j });
			}
		}
	}
	sort(all(res));
	cout << res[0].first + 1 << " " << res[0].second + 1 << " " << ans << "\n";
}