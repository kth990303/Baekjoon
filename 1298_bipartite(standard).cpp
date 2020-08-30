// 200830 #1298 노트북의 주인을 찾아서 Platinum V
// 전형적인 이분매칭
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 5001;
int d[MAX], N, M, ans;
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
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	for (int i = 1; i <= N; i++) {
		fill(used, used + MAX, false);
		if (dfs(i))
			ans++;
	}
	cout << ans << "\n";
}