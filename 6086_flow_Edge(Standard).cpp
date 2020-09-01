//200901 �ֵ���ī�� feat. Struct Edge
//�������� ��������� �带 �� ����!
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 53;
const int INF = 1000000007;
int N, ans;
// Edge�� �̿��� Ǯ��
struct Edge {
	int to, c, f;
	Edge* rev;
	// Edge ������
	Edge() :Edge(-1, 0){}
	Edge(int to1, int c1) 
		:to(to1), c(c1), f(0), rev(nullptr) {}
	// ���� �뷮
	int remain() {
		return c - f;
	}
	// ���� �߰�
	void push(int x) {
		f += x;
		rev->f -= x;
	}
};
vector<Edge*> v[MAX];
// ���� -> ����
int ctoi(char c) {
	// 0~25
	if (c <= 'Z')
		return c - 'A';
	// 26~51
	return c - 'a' + 26;
}
// �ִ����� ��� �Լ�
void maxFlow(int s, int e) {
	while (1) {
		int prev[MAX];	// ���� ��� ����
		Edge* path[MAX] = { 0 };	// ���� ����
		fill(prev, prev + MAX, -1);	// ���� ���� �ʱ�ȭ
		
		queue<int> q;
		q.push(s);
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (Edge* i : v[x]) {
				int next = i->to;
				// �ܿ����� ���Ұ�, �湮���� ���� ���
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

	cin >> N;
	for (int i = 0; i < N; i++) {
		char a, b;
		int c;
		cin >> a >> b >> c;
		// ���ڸ� ���ڷ�
		a = ctoi(a);
		b = ctoi(b);
		// Edge ����
		Edge* e1 = new Edge(b, c);
		Edge* e2 = new Edge(a, c);
		// ���� ���� ����, �����⵵
		e1->rev = e2;
		e2->rev = e1;
		v[a].push_back(e1);
		v[b].push_back(e2);
	}
	maxFlow(ctoi('A'), ctoi('Z'));
	cout << ans << "\n";
}