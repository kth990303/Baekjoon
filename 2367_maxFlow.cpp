// 200912 #2367 파티 Platinum IV
// 네트워크 플로우는 구현이 어려운 게 아니라 어떻게할 지가 어려움
// 파티에 가져올 수 있는 접시의 최대 개수
// 음식 종류에 따른 접시 수를 싱크에 보내는 유량으로
// 사람이 음식을 가져오는 경우니까
// 소스->사람, 음식 종류->싱크
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 302;
const int INF = 1000000007;
struct Edge {
	int to, c, f;
	Edge* rev;
	Edge() :Edge(-1, 0) {}
	Edge(int to1, int c1)
		:to(to1), c(c1), f(0), rev(nullptr) {}
	int remain() {
		return c - f;
	}
	void push(int x) {
		f += x;
		rev->f -= x;
	}
};
vector<Edge*> v[MAX];
inline void addEdge(int a, int b, int c) {
	Edge* e1 = new Edge(b, c);
	Edge* e2 = new Edge(a, 0);
	e1->rev = e2;
	e2->rev = e1;
	v[a].push_back(e1);
	v[b].push_back(e2);
}
int N, K, D, ans;
void maxFlow(int s, int e) {
	while (1) {
		int prev[MAX];
		Edge* path[MAX] = { 0 };
		fill(prev, prev + MAX, -1);
		queue<int> q;
		q.push(s);
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (auto i : v[x]) {
				int next = i->to;
				if (i->remain() > 0 && prev[next] == -1) {
					q.push(next);
					prev[next] = x;
					path[next] = i;
					if (next == e)
						break;
				}
			}
		}
		if (prev[e] == -1)
			break;
		int flow = INF;
		for (int i = e; i != s; i = prev[i]) {
			flow = min(flow, path[i]->remain());
		}
		for (int i = e; i != s; i = prev[i]) {
			path[i]->push(flow);
		}
		ans += flow;
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int S = 0, E = 301;
	cin >> N >> K >> D;
	// S: 0, 사람: 1~200, 음식종류: 201~300, E: 301
	for (int i = 1; i <= D; i++) {
		int j;
		cin >> j;
		addEdge(i + 200, E, j);
	}
	for (int i = 1; i <= N; i++) {
		addEdge(S, i, K);
	}
	for (int i = 1; i <= N; i++) {
		int cnt;
		cin >> cnt;
		for (int j = 1; j <= cnt; j++) {
			int num;
			cin >> num;
			addEdge(i, num + 200, 1);
		}
	}
	maxFlow(S, E);
	cout << ans << "\n";
}