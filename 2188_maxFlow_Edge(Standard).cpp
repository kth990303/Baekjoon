#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 402;
const int INF = 1000000007;
int ans, N, M;
struct Edge {
	int to, c, f;
	Edge* rev;
	// ������
	Edge() :Edge(-1, 0) {}
	Edge(int to1, int c1)
		:to(to1), c(c1), f(0), rev(nullptr) {}
	// �ܿ� ���� ����
	int remain() {
		return c - f;
	}
	// ���� ���������
	void push(int x) {
		f += x;
		rev->f -= x;
	}
};
vector<Edge*> v[MAX];
// �뷮�� c�� a->b�� ������ �߰��ϴ� �Լ�
inline void addEdge(int a, int b, int c) {
	// ������ �뷮�� c
	Edge* e1 = new Edge(b, c);
	// ������ �뷮�� 0 (������� ��� ������ �� ����)
	Edge* e2 = new Edge(a, 0);
	e1->rev = e2;
	e2->rev = e1;
	v[a].push_back(e1);
	v[b].push_back(e2);
}
// ������ ī�� �˰���
void maxFlow(int s, int e) {
	while (1) {
		int prev[MAX];	// ���� ��ġ ����
		Edge* path[MAX] = { 0 };	// ���� ����
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

	cin >> N >> M;
	// S: 0 E: 401, ��: 1~200, ���: 201~400
	int S = 0, E = 401;
	// �� ���� �ʱ�ȭ
	for (int i = 1; i <= N; i++) {
		addEdge(0, i, 1);
	}
	// ��� ���� �ʱ�ȭ
	for (int i = 1; i <= M; i++) {
		addEdge(i + 200, E, 1);
	}
	// ��-��� ���� �ʱ�ȭ
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		while (num--) {
			int j;
			cin >> j;
			addEdge(i, j + 200, 1);
		}
	}
	maxFlow(S, E);
	cout << ans << "\n";
}