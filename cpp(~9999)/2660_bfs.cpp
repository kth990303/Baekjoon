// 200930 #2660 회장 뽑기 Gold V
// BFS 풀이
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int MAX = 51;
const int INF = 1e9 + 7;
int N;
bool visit[MAX];
vector<int> v[MAX];
int bfs(int num) {
	queue<pair<int, int>> q;
	fill(visit, visit + MAX, false);
	int ans = 0;
	q.push({num, 0});
	visit[num] = true;
	while (!q.empty()) {
		int x = q.front().first;
		int score = q.front().second;
		q.pop();
		ans = max(ans, score);
		for (int i : v[x]) {
			if (!visit[i]) {
				q.push({ i, score + 1 });
				visit[i] = true;
			}
		}
	}
	return ans;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int a, b;
	cin >> N;
	while (cin >> a >> b) {
		if (a == -1 && b == -1)
			break;
		// Undirected Graph임에 주의
		v[a].push_back(b);
		v[b].push_back(a);
	}
	vector<pair<int, int>> ans;
	vector<pair<int, int>> result;
	int min_score = INF;
	for (int i = 1; i <= N; i++) {
		// N명의 점수 파악을 위해 N번 bfs 돌림
		int s = bfs(i);
		ans.push_back({i, s});
		// 그 중 최소 점수 갱신
		min_score = min(min_score, s);
	}
	// 최소점수인 애들은 result 배열에 넣음
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i].second == min_score)
			result.push_back(ans[i]);
	}
	// 결과 출력
	cout << min_score << " " << result.size() << "\n";
	for (auto i : result) {
		cout << i.first << " ";
	}
}