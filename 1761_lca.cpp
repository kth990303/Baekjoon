// 200822 최소 공통 조상 #1761 Platinum V
// kks227님 블로그로 도움을 얻음
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
// MAX 값은 올림으로!
const int MAX = 16;	// 2^16=65536
int p[40001][MAX + 1];	// 부모 배열 (i의 2^j번째 조상 배열)
vector<pair<int, int>> v[40001];
int d[40001];	// 깊이 배열
int len[40001];	// 거리 배열
int N, M;
// 거리, 깊이 초기화 및 직접적인 조상만 초기화
void init(int cur) {
	for (auto i : v[cur]) {
		if (d[i.first] == -1) {
			len[i.first] = len[cur] + i.second;
			d[i.first] = d[cur] + 1;
			p[i.first][0] = cur;
			init(i.first);
		}
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int a, b, cost;
		cin >> a >> b >> cost;
		v[a].push_back({ b, cost });
		v[b].push_back({ a,cost });
	}
	memset(p, -1, sizeof(p));
	fill(d, d + N+1, -1);
	d[1] = 0;
	// initialize tree
	init(1);
	// initialize all parent info
	for (int j = 0; j < MAX; j++) {
		for (int i = 2; i <= N; i++) {
			int tmp = p[i][j];
			if (tmp != -1) {
				p[i][j + 1] = p[tmp][j];
			}
		}
	}
	// query
	cin >> M;
	while (M--) {
		int a, b, ans = 0;
		cin >> a >> b;
		int lenA = len[a];
		int lenB = len[b];
		if (d[a] < d[b]) swap(a, b);
		int diff = d[a] - d[b];

		int j = 0;
		while (diff) {
			// O(lgN)
			if (diff % 2) {
				a = p[a][j];
			}
			diff /= 2;
			j++;
		}
		// 다를 경우 조상을 찾아서
		if (a != b) {
			for (int j = MAX; j >= 0; j--) {
				// 공통조상 전까지 진행
				if (p[a][j] != -1 && p[a][j] != p[b][j]) {
					a = p[a][j];
					b = p[b][j];
				}
			}
			// 공통조상으로 올리기
			a = p[a][0];
		}
		int lenLCA = len[a];
		cout << lenA + lenB - 2 * lenLCA << "\n";
	}
}