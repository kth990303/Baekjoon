// 200902 #10976 �ǳ� Platinum III
// 1->N������ �ִ� �� ���� �ǳ� ���� �� �ִ���
// �ִ����� (����� ������ �����Ƿ� mcmf�� �ƴ�)
// �׽�Ʈ ���̽����� �ʱ�ȭ ����ߵ�.
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 202;
const int INF = 1000000007;
int N, M, ans;
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
void maxFlow(int s, int e) {
	while (1) {
		int prev[MAX];
		// �ʱ�ȭ �����൵ ��� ������,
		// �̿��̸� �������ͷ� ����ϰ� ������
		Edge* path[MAX] = { 0 };
		fill(prev, prev + MAX, -1);
		queue<int> q;
		q.push(s);
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (Edge* i : v[x]) {
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

	int t;
	cin >> t;
	while (t--) {
		for (auto& i : v)
			i.clear();
		ans = 0;
		cin >> N >> M;
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			addEdge(a, b, 1);
		}
		maxFlow(1, N);
		cout << ans << "\n";
	}
}