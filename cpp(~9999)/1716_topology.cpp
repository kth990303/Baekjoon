// 200820 #1766 topology sort && priority_queue
// Gold II
// 무난한 topology이나, priority_queue까지 고려해야 함
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v[32001];
int in[32001];
int N, M;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		in[b]++;
		v[a].push_back(b);
	}
	// 일반적인 큐로 하면 3 4 1 2
	// 가급적 쉬운문제
	priority_queue<int, vector<int>, greater<int>> pq;
	for (int i = 1; i <= N; i++) {
		if (!in[i]) {
			pq.push(i);
		}
	}
	for (int i = 1; i <= N; i++) {
		int t = pq.top();
		cout << t << " ";
		pq.pop();
		sort(v[t].begin(), v[t].end());
		for (auto i : v[t]) {
			if (--in[i] == 0)
				pq.push(i);
		}
	}
}