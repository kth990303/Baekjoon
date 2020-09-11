// 200912 #2367 ��Ƽ Platinum IV
// ��Ʈ��ũ �÷ο�� ������ ����� �� �ƴ϶� ����� ���� �����
// ��Ƽ�� ������ �� �ִ� ������ �ִ� ����
// ���� ������ ���� ���� ���� ��ũ�� ������ ��������
// ����� ������ �������� ���ϱ�
// �ҽ�->���, ���� ����->��ũ
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
	// S: 0, ���: 1~200, ��������: 201~300, E: 301
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