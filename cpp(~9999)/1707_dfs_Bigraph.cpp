// 200906 #1707 이분그래프 Gold IV
// 이분 그래프 (Bipartite Graph) 연습문제
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 20001;
vector<int> v[MAX];
int V, E;
int color[MAX];
// dfs로 자신의 색과 반대되는 색을 칠해준다
bool dfs(int x, int num) {
	color[x] = num;
	// 연결돼있는 정점 확인
	for (auto i : v[x]) {
		// 같은 색깔이면 false 리턴
		if (color[i] == num) {
			return false;
		}
		// 아직 방문 안한 경우
		else if (!color[i]) {
			color[i] = -num;
			// 이거 false인 경우 무조건 false 리턴하게
			if (!dfs(i, -num))
				return false;
		}
	}
	return true;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		cin >> V >> E;
		for (auto& i : v)
			i.clear();
		fill(color, color + MAX, 0);
		// No: 0, Red: 1, Blue: -1
		for (int i = 0; i < E; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		bool biGraph = true;
		for (int i = 1; i <= V; i++) {
			if (!color[i]) {
				if (!dfs(i, 1)) {
					cout << "NO\n";
					biGraph = false;
					break;
				}
			}
		}
		if (biGraph) {
			cout << "YES\n";
		}
	}
}