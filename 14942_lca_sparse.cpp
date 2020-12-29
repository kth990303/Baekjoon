// 201229 #14942 개미 Platinum V
// sparse_table O(nlgn) (lca는 아니지만 연습하기에 좋음)
// dfs+sparse_table 또는 bfs+sparse_table
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int MAX = 100001;
const int SIZE = 17;
vector<pair<int, int>> v[MAX];
int N, hp[MAX], p[MAX][SIZE], d[MAX], cost[MAX][SIZE];
void init(int cur) {
	for (auto i : v[cur]) {
		if (d[i.second] == -1) {
			// cost (체력 소모) 배열 또한 만들어준다.
			cost[i.second][0] = i.first;
			// 노드의 깊이 설정
			d[i.second] = d[cur] + 1;
			// 부모 설정
			p[i.second][0] = cur;
			init(i.second);
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> hp[i];
	}
	for (int i = 0; i < N - 1; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		v[a].push_back({ cost, b });
		v[b].push_back({ cost, a });
	}
	memset(p, -1, sizeof(p));
	fill(d, d + MAX, -1);
	d[1] = 0;
	init(1);	// 기존 lca와 동일
	// 왜 SIZE-1까지?
	// j+1=SIZE-1이기 때문에. 배열 index 주의하자.
	for (int j = 0; j < SIZE - 1; j++) {
		for (int i = 2; i <= N; i++) {
			if (p[i][j] != -1) {
				p[i][j + 1] = p[p[i][j]][j];
				cost[i][j + 1] = cost[i][j] + cost[p[i][j]][j];
			}
			// else문이 없으면 무조건 루트노드로 갈 수 있게 됨.
			else
				cost[i][j + 1] = cost[i][j];
		}
	}
	for (int i = 1; i <= N; i++) {
		// 이 문제가 lca가 아닌 이유
		// 한 개의 노드가 최대 얼마까지 올라갈 수 있는지
		// 공통조상을 구하는 문제가 아님
		int a, k;
		a = i, k = hp[i];
		if (i == 1) {
			cout << "1\n";
			continue;
		}
		for (int j = SIZE - 1; j >= 0; j--) {
			if (a == -1)
				break;
			if (k >= cost[a][j]) {
				k -= cost[a][j];
				a = p[a][j];	// -1인 경우 루트노드 이상
			}
		}
		if (a == -1)
			a = 1;
		// 이 코드 없어도 되는데, 왜 이 부분이 없으면 20ms가 더 느리지..?
		else if (k >= cost[a][0])
			a = p[a][0];
		cout << a << "\n";
	}
}