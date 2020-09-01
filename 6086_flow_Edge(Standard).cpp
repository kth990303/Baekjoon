//200901 애드몬드카프 feat. Struct Edge
//파이프는 양방향으로 흐를 수 있음!
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
const int MAX = 53;
const int INF = 1000000007;
int N, ans;
// Edge를 이용한 풀이
struct Edge {
	int to, c, f;
	Edge* rev;
	// Edge 생성자
	Edge() :Edge(-1, 0){}
	Edge(int to1, int c1) 
		:to(to1), c(c1), f(0), rev(nullptr) {}
	// 남은 용량
	int remain() {
		return c - f;
	}
	// 유량 추가
	void push(int x) {
		f += x;
		rev->f -= x;
	}
};
vector<Edge*> v[MAX];
// 문자 -> 숫자
int ctoi(char c) {
	// 0~25
	if (c <= 'Z')
		return c - 'A';
	// 26~51
	return c - 'a' + 26;
}
// 최대유량 계산 함수
void maxFlow(int s, int e) {
	while (1) {
		int prev[MAX];	// 이전 노드 저장
		Edge* path[MAX] = { 0 };	// 간선 저장
		fill(prev, prev + MAX, -1);	// 저장 여부 초기화
		
		queue<int> q;
		q.push(s);
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			for (Edge* i : v[x]) {
				int next = i->to;
				// 잔여량이 남았고, 방문하지 않은 경우
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
		// 문자를 숫자로
		a = ctoi(a);
		b = ctoi(b);
		// Edge 생성
		Edge* e1 = new Edge(b, c);
		Edge* e2 = new Edge(a, c);
		// 간선 방향 설정, 역방향도
		e1->rev = e2;
		e2->rev = e1;
		v[a].push_back(e1);
		v[b].push_back(e2);
	}
	maxFlow(ctoi('A'), ctoi('Z'));
	cout << ans << "\n";
}