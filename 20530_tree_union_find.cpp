// 210201 #20530 ¾çºÐ Gold II
// Union-find + tree cycle + Offline Query + bfs
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAX = 200001;
int N, Q, in[MAX], p[MAX];
vector<int> v[MAX];
bool visit[MAX];
// Union-Find
int find(int a) {
	if (a == p[a])
		return a;
	return p[a] = find(p[a]);
}
bool merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return false;
	p[b] = a;
	return true;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> Q;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
		// check the cycle
		in[a]++;
		in[b]++;
	}
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		if (in[i] == 1)
			q.push(i);
	}
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		in[cur]--;
		for (auto i : v[cur]) {
			if (!in[i]) continue;
			// when cycle, in[i]=2
			if (--in[i] == 1)
				q.push(i);
		}
	}
	// union-find init
	for (int i = 0; i <= N; i++) {
		p[i] = i;
	}
	for (int i = 1; i <= N; i++) {
		if (in[i]) {
			q.push(i);
			visit[i] = true;
			while (!q.empty()) {
				int cur = q.front();
				q.pop();
				for (auto i : v[cur]) {
					// do not check other cycle(in[i]==2)
					if (!visit[i] && !in[i]) {
						// same cycle->merge
						merge(cur, i);
						visit[i] = true;
						q.push(i);
					}
				}
			}
		}
	}
	// offline query: O(Q)
	while (Q--) {
		int a, b;
		cin >> a >> b;
		if (find(a) != find(b))
			cout << 2 << "\n";
		else
			cout << 1 << "\n";
	}
}