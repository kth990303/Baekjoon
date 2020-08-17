#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<pair<int, int>> v[101];
int inDegree[101];
int result[101][101];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int N, M, normal = 0;
	cin >> N >> M;
	for (int i = 1; i <= M; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		v[b].push_back({ a,c });
		inDegree[a]++;
	}
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (!inDegree[i]) {
			q.push(i);
			normal = max(normal, i);
			result[i][i] = 1;
		}
	}

	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		for (auto next : v[cur]) {
			for(int i=1;i<=N;i++)
				result[next.first][i] += result[cur][i]*next.second;
			inDegree[next.first]--;
			if (!inDegree[next.first])
				q.push(next.first);
		}
	}

	for (int i = 1; i <= normal; i++) {
		if(result[N][i])
			cout << i << " " << result[N][i] << "\n";
	}
}