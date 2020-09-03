// 200903 #11408 열혈강호5 Platinum III
// 간선 구조체 풀이: 공간복잡도 감소
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 802;
const int INF = 1000000007;
int N, M, ans, w;
struct Edge {
	// mcmf일 땐 cost 추가
	int to, c, f, cost;
	Edge* rev;
	Edge() :Edge(-1, 0, 0) {}
	Edge(int to1, int c1, int cost1)
		:to(to1), c(c1), f(0), cost(cost1), rev(nullptr) {}
	int remain() {
		return c - f;
	}
	void push(int x) {
		f += x;
		rev->f -= x;
	}
};
vector<Edge*> v[MAX];
// 용량이 c, 비용이 d인 a->b 간선 생성
inline void addEdge(int a, int b, int c, int d) {
	Edge* e1 = new Edge(b, c, d);
	Edge* e2 = new Edge(a, 0, -d);
	e1->rev = e2;
	e2->rev = e1;
	v[a].push_back(e1);
	v[b].push_back(e2);
}
void mcmf(int s, int e) {
	while (1) {
		int prev[MAX], d[MAX];	// d: 비용 기록
		Edge* path[MAX] = { 0 };
		bool inQ[MAX] = { 0 };	// 큐에 정점이 있는가
		fill(prev, prev + MAX, -1);
		fill(d, d + MAX, INF);	// 최소비용이므로 INF로 초기화
		queue<int> q;
		q.push(s);
		d[s] = 0;
		inQ[s] = true;
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			inQ[x] = false;	// 큐에서 꺼냄 (SPFA)
			for (Edge* i : v[x]) {
				int next = i->to;
				// feat.벨만 포드
				if (i->remain() > 0 && d[next] > d[x] + i->cost) {
					prev[next] = x;
					path[next] = i;
					d[next] = d[x] + i->cost;
					if (!inQ[next]) {
						q.push(next);
						inQ[next] = true;
					}
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
			w += path[i]->cost;	// 비용 갱신
		}
		ans += flow;
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	int S = 0, E = 801;
	// S: 0, 직원: 1~400, 일: 401~800, E: 801
	for (int i = 1; i <= N; i++) {
		addEdge(S, i, 1, 0);
		int cnt;
		cin >> cnt;
		while (cnt--) {
			int j, c;
			cin >> j >> c;
			addEdge(i, j + 400, 1, c);
		}
	}
	for (int i = 1; i <= M; i++) {
		addEdge(i + 400, E, 1, 0);
	}
	mcmf(S, E);
	cout << ans << "\n";
	cout << w << "\n";
}