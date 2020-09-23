// 200923 #1068 트리 Silver I
// 루트노드는 0이 아닐 수도 있음
#include <iostream>
#include <vector>
using namespace std;
const int MAX = 51;
// 트리 저장
vector<int> v[MAX];
int N, ans, num;	// num: 지우는 노드
bool visit[MAX];	// 방문 여부
vector<int> first;	// 루트 노드 모음
void dfs(int cur) {
	visit[cur] = true;
	bool flag = true;	// 리프노드인지의 여부
	for (auto i : v[cur]) {
		// 지우는 노드일 경우 무시
		// 방문을 안한 경우
		if (!visit[i] && i!=num) {
			flag = false;	// 자식노드가 존재하므로
			visit[i] = true;
			dfs(i);
		}
	}
	if (flag && cur!=num)
		ans++;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		int p;
		cin >> p;
		if (p != -1) {
			v[p].push_back(i);
			v[i].push_back(p);
		}
		else
			first.push_back(i);
	}
	cin >> num;
	// 자식 노드 지워줌
	// 그러나, 아직 부모에서 num으로 향하는 노드는 존재
	v[num].erase(v[num].begin(), v[num].end());
	for (auto i : first)
		dfs(i);
	cout << ans << "\n";
}