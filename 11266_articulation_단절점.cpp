// 200902 #11266 단절점 Platinum V
// crocus님 블로그 참고
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 10001;
int d[MAX], V, E, id;
vector<int> v[MAX];
vector<int> answer;	// 단절점 목록
bool ans[MAX];	// 단절점 여부
int dfs(int x, bool isRoot) {
	d[x] = ++id;
	int ret = d[x];
	int child = 0;
	for (auto i : v[x]) {
		// 탐색된 정점이라면
		if (d[i]) {
			// 더 먼저 탐색된 정점을 ret으로
			ret = min(ret, d[i]);
			continue;
		}
		child++;
		int prev = dfs(i, false);
		// 루트 노드가 아닐 경우
		// 자식 노드들이 자신보다 더 빠른 방문번호를 가진 정점 가능하다면 단절점
		if (!isRoot && prev >= d[x]) {
			ans[x] = true;
		}
		ret = min(ret, prev);
	}
	// 루트 노드일 경우 자식 수가 2개 이상이면 단절점
	if (isRoot && child>=2) {
		ans[x]=true;
	}
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> V >> E;
	for (int i = 0; i < E; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	for (int i = 1; i <= V; i++) {
		if (!d[i])
			dfs(i, true);
	}
	int cnt = 0;
	for (int i = 1; i <= V; i++) {
		if (ans[i])
			answer.push_back(i);
	}
	cout << answer.size() << "\n";
	for (auto i : answer)
		cout << i << " ";
	cout << "\n";
}