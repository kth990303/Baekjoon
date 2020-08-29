// 200829 #2188 축사 배정 Platinum IV
// 이분매칭의 기본 중 기본
// 개인적으론 기본은 플5급인데... 이분매칭은 플4로 약속이 돼있나봄
#include <iostream>
#include <vector>
const int MAX = 201;
using namespace std;
int N, M, d[MAX];
bool used[MAX];
vector<int> v[MAX];
bool dfs(int x) {
	for (auto i : v[x]) {
		// 간선이 새로 들어오는 경우일 땐 다 false
		// 이 경우는 이미 옮겨진 경우.
		// 간선이 새로 들어오는 경우 아니면 더이상 안옮김
		if (used[i])
			continue;
		used[i] = true;
		// !d[i]: 아직 배정이 되지 않은 경우
		// dfs(d[i])가 true일 경우 원래 배정된 애가 다른 곳으로 이동돼서 비게 된 경우
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
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		while (num--) {
			int j;
			cin >> j;
			v[i].push_back(j);
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		// 새로 매칭할 때는 이전 매칭을 건드릴 수 있으니까
		fill(used, used + MAX, false);
		// 매칭이 되면 ans++
		if (dfs(i))
			ans++;
	}
	// 매칭된 수
	cout << ans << "\n";
}
