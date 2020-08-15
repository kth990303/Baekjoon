// 200815 백준 1504 주석풀이 <다익스트라> 골드4
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
const int INF = 1000000000;
vector<pair<int, int>> v[801];
int N, E;
int dijkstra(int s, int e) {
	// 시작점, 끝점 같을 경우
	if (s == e)
		return 0;
	// 비용 초기화
	int d[801] = { 0 };
	// 최소비용을 구하므로 처음 값은 INF
	for (int i = 1; i <= N; i++) {
		d[i] = INF;
	}
	// 비용을 우선순위로 하는 큐 생성
	// priority_queue<T, vector<T>, greater<T>> pq; 도 가능
	priority_queue<pair<int, int>> pq;
	pq.push({ 0, s });
	// 처음 비용은 0이잖아~
	d[0] = 0;
	// bfs처럼 해볼까~
	// pq 빌 때까지 하면 모든 경로 고려한 최단경로 가능임
	while (!pq.empty()) {
		int cur = pq.top().second;
		// 비용이 최소인 것을 하므로 음수로
		// 어차피 다익스트라는 양수일 때만 가능하니까
		// 그 이유는 밑에~
		int cost = -pq.top().first;
		pq.pop();
		// 음수일 때가 안되는 이유
		// cost보다 작은 경우는 오히려 최장거리가 되니까 이 if문 성립안해
		// 음수: 밸만 포드 가자~ (개어려워 ㅠㅜㅜ 200815)
		if (d[cur] < cost)
			continue;
		for (int i = 0; i < v[cur].size(); i++) {
			// s와 연결돼있는 간선들 따져볼까
			int next = v[cur][i].first;
			// 현재까지 비용+다음 비용
			int nCost = v[cur][i].second + cost;
			if (nCost < d[next]) {
				// 비용 최소인 경우
				// 단, 처음엔 INF일테니 첫단추인 경우 무조건 수정됨.
				d[next] = nCost;
				// 이제 pq에 넣어보자
				pq.push({ -nCost, next });
			}
		}
	}
	return d[e];
}
int main()
{
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}

	int s1, s2;
	cin >> s1 >> s2;
	// 휴... 두 점이라 정말 다행이다ㅋㅋ
	int a1 = dijkstra(1, s1) + dijkstra(s1, s2) + dijkstra(s2, N);
	int a2 = dijkstra(1, s2) + dijkstra(s2, s1) + dijkstra(s1, N);
	int ans = min(a1, a2);
	// INF 근처일 경우 경로가 없는 경우가 있었다는 거니까
	if (ans >= 200000 * N || ans <= 0)
		cout << -1;
	else
		cout << ans;
}