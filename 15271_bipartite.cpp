// 200912 #15271 친구 팰린드롬2 Platinum V
// 이분 매칭
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 201;
int N, M, d[MAX];
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
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		// 다른 성별일 경우에만 매칭
		if (a % 2 != b % 2) {
			// a가 남자인 경우는 여자로 바꿔주자
			if (!(a % 2))
				swap(a, b);
			// 여자 -> 남자 매칭
			v[a].push_back(b);
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		fill(used, used + MAX, false);
		// 짝이 지어졌으니 2명 모두 무대 위 가능
		if (dfs(i))
			ans += 2;
	}
	// 모두 짝지어지지 않은 경우 혼자 춤추는 애 있음
	if (ans != N)
		ans++;
	cout << ans << "\n";
}