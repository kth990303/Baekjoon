// 200930 #2660 ȸ�� �̱� Gold V
// BFS Ǯ��
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
		// Undirected Graph�ӿ� ����
		v[a].push_back(b);
		v[b].push_back(a);
	}
	vector<pair<int, int>> ans;
	vector<pair<int, int>> result;
	int min_score = INF;
	for (int i = 1; i <= N; i++) {
		// N���� ���� �ľ��� ���� N�� bfs ����
		int s = bfs(i);
		ans.push_back({i, s});
		// �� �� �ּ� ���� ����
		min_score = min(min_score, s);
	}
	// �ּ������� �ֵ��� result �迭�� ����
	for (int i = 0; i < ans.size(); i++) {
		if (ans[i].second == min_score)
			result.push_back(ans[i]);
	}
	// ��� ���
	cout << min_score << " " << result.size() << "\n";
	for (auto i : result) {
		cout << i.first << " ";
	}
}