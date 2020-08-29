// 200829 #11438 LCA 2 Platinum V
// LCA 2 공부
// LCA는 O(logN)이 국룰이지
// <cmath> 빼니까 0.12ms 빨라짐
#include <iostream>
#include <cstring>
#include <vector>
const int MAX = 100001;
const int SIZE = 17;	// ceil(log2(MAX))
using namespace std;
int p[MAX][SIZE + 1];	// 트리 부모 배열
vector<int> v[MAX];	// 트리 간선
int N, M, d[MAX];	// 트리의 높이(깊이)
void init(int cur) {
	for (auto i : v[cur]) {
		// 깊이 설정을 하지 않았다면
		if (d[i] == -1) {
			// 현재꺼보다 한단계 깊은 깊이
			d[i] = d[cur] + 1;
			// 따라서 i의 2^0번째 조상 (첫 번째 조상)
			p[i][0] = cur;
			// dfs 성질
			init(i);
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	// 초기화
	memset(p, -1, sizeof(p));
	fill(d, d + MAX, -1);
	d[1] = 0;
	init(1);
	// p 배열 초기화
	for (int j = 0; j < SIZE; j++) {
		for (int i = 2; i <= N; i++) {
			// tmp는 i의 2^j번째 조상
			int tmp = p[i][j];
			if (tmp != -1) {
				// i의 2^(j+1)번째 조상은
				// tmp의 2^j번째 조상 (거듭제곱 성질)
				p[i][j + 1] = p[tmp][j];
			}
		}
	}
	// query: a,b공통조상 찾기
	cin >> M;
	while (M--) {
		int a, b;
		cin >> a >> b;
		// 깊은 거를 우선으로 하자
		if (d[a] < d[b]) swap(a, b);
		int diff = d[a] - d[b];

		// O(logN)인 이유
		// a와 b가 높이차가 없어질 때까지 이동
		int j = 0;
		while (diff) {
			if (diff % 2)
				a = p[a][j];
			diff /= 2;
			j++;
		}
		if (a != b) {
			for (int j = SIZE; j >= 0; j--) {
				// 루트노드보다 높지 않은 내에서 공통조상 만나기 전까지
				if (p[a][j] != -1 && p[a][j] != p[b][j]) {
					a = p[a][j];
					b = p[b][j];
				}
			}
			// 공통조상이 바로 위에
			a = p[a][0];
		}
		cout << a << "\n";
	}
}