// 200903 #3640 제독 Platinum II
// 포탄을 가장 적게, mcmf로
// 두 전함: 출발/도착지점 용량은 2
// 나머지 지점은 방문x -> 분신 후 1씩 용량 부여
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int INF = 1000000007;
const int MAX = 2002;
int _V, _E, ans, w;
struct Edge {
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
		int prev[MAX], d[MAX];
		bool inQ[MAX] = { 0 };
		Edge* path[MAX] = { 0 };
		fill(prev, prev + MAX, -1);
		fill(d, d + MAX, INF);
		queue<int> q;
		q.push(s);
		d[s] = 0;
		inQ[s] = true;
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			inQ[x] = false;
			for (Edge* i : v[x]) {
				int next = i->to;
				if (i->remain() > 0 && d[next] > d[x] + i->cost) {
					prev[next] = x;
					path[next] = i;
					d[next] = d[x] + i->cost;
					if (!inQ[next]) {
						inQ[next] = true;
						q.push(next);
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
			w += path[i]->cost;
		}
		ans += flow;
	}
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	// 중간지점: 1~1000, 중간지점 분신: 1001~2000
	while (cin >> _V >> _E) {
		int S = 0, E = 2001;
		for (auto& i : v)
			i.clear();
		ans = 0, w = 0;
		addEdge(S, 1, 2, 0);
		addEdge(_V + 1000, E, 2, 0);

		addEdge(1, 1001, 2, 0);
		addEdge(_V, _V+1000, 2, 0);
		for (int i = 2; i < _V; i++) {
			addEdge(i, i + 1000, 1, 0);
		}
		for (int i = 0; i < _E; i++) {
			int a, b, c;
			cin >> a >> b >> c;
			addEdge(a+1000, b, 1, c);
		}
		mcmf(S, E);
		cout << w << "\n";
	}
}