// 200904 #17481 최애 정하기 Platinum V
// 개인적으론 Platinum IV 라고 봄.
// 전형적인 이분매칭...이나 TLE를 겪을수도?
#include <iostream>
#include <vector>
#include <string>
using namespace std;
const int MAX = 1001;
string s1[MAX];
int N, M, d[MAX], ans;
bool used[MAX];
vector<int> v[MAX];
bool dfs(int x) {
	for (auto i : v[x]) {
		if (used[i])
			continue;
		used[i] = true;
		if (!d[i] || dfs(d[i])) {
			d[i] = x;
			return true;
		}
	}
	return false;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		cin >> s1[i];
	}
	for (int i = 1; i <= N; i++) {
		int cnt;
		cin >> cnt;
		while (cnt--) {
			string s;
			cin >> s;
			for (int j = 1; j <= M; j++) {
				if (s == s1[j]) {
					v[i].push_back(j);
					// break 안해주면 TLE
					break;
				}
			}
		}
	}
	for (int i = 1; i <= N; i++) {
		fill(used, used + MAX, false);
		if (dfs(i))
			ans++;
	}
	if (ans == N)
		cout << "YES\n";
	else
		cout << "NO\n" << ans << "\n";
}