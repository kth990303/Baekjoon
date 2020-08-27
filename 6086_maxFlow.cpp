// 200827 #6086 최대 유량 Platinum IV
// 최대유량 문제 (이분매칭의 기초) 연습
// 나동빈 블로그, 라이 블로그 참조
// 아직 연습이 많이 필요하다
// O(VE^2)
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
const int MAX = 53;	// 알파벳 A~Z, a~z
const int INF = 1000000007;
using namespace std;
int c[MAX][MAX], f[MAX][MAX], d[MAX];
vector<int> v[MAX];
int N, ans;
int ctoi(char c) {
	if (c >= 'a' && c <= 'z')
		return c - 'a' + 26;
	return c - 'A';
}
void maxFlow(int s, int e) {
	while (1) {
		// 방문하지 않은 지점은 -1로 초기화
		fill(d, d + MAX, -1);
		queue<int> q;
		q.push(s);
		// bfs로 노드 탐색
		while (!q.empty()) {
			int x = q.front();
			q.pop();
			// 유량을 흘려보내주자
			for (auto y : v[x]) {
				// 유량이 용량에 꽉 차지 않아 여유가 있는지
				// 아직 방문하지 않은 점 중에서
				if (c[x][y] - f[x][y] > 0 && d[y] == -1) {
					q.push(y);
					d[y] = x;	// 경로 기억
					if (y == e)	// 끝지점이면 탈출
						break;
				}
			}
		}
		// 끝지점 경로 없을 경우 탈출
		if (d[e] == -1)
			break;
		int flow = INF;
		for (int i = e; i != s; i = d[i]) {
			flow = min(flow, c[d[i]][i] - f[d[i]][i]);
		}
		// 가장 작은 유량만큼 역으로 흘려줌
		for (int i = e; i != s; i = d[i]) {
			f[d[i]][i] += flow;	// 이전꺼에 더해줌
			f[i][d[i]] -= flow;	// 현재꺼에서 빼주고
		}
		// 역으로 보내줘서 가성비 이득본거 추가해줌
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
		int w;
		cin >> a >> b >> w;
		a = ctoi(a);
		b = ctoi(b);
		v[a].push_back(b);
		v[b].push_back(a);
		// 같은 간선이 여러번 들어올 수 있음!
		// + 안붙여주면 틀림...
		c[a][b] += w;
		// 양방향이니까 이거 안해줘도 틀림...
		c[b][a] += w;
	}
	maxFlow(ctoi('A'), ctoi('Z'));
	cout << ans << "\n";
}