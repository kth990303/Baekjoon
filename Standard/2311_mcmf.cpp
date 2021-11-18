// 211118 #2311 ¿Õº¹¿©Çà Platinum III
// mcmf Standard O(NM) cause of spfa
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MAX = 1003;
const int INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e6;
int N, M, w, ans;
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
inline void addEdge(int a, int b, int c, int cost) {
	Edge* e1 = new Edge(b, c, cost);
	Edge* e2 = new Edge(a, 0, -cost);
	e1->rev = e2;
	e2->rev = e1;
	v[a].push_back(e1);
	v[b].push_back(e2);
}
void mcmf(int s, int e) {
	while (1) {
		int prev[MAX], d[MAX];
		Edge* path[MAX];
		bool inQ[MAX];
		fill(prev, prev + MAX, -1);
		fill(d, d + MAX, INF);
		fill(path, path + MAX, nullptr);
		fill(inQ, inQ + MAX, false);
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
			w += path[i]->cost;
		}
		ans += flow;
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> M;
	int S = 0, E = 1001;
	addEdge(S, 1, 2, 0);
	for (int i = 0; i < M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		addEdge(a, b, 1, c);
		addEdge(b, a, 1, c);
	}
	addEdge(N, E, 2, 0);
	mcmf(S, E);
	cout << w << "\n";
}