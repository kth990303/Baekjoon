// 200918 #11097 도시 계획 Platinum IV
// SCC인듯 SCC아닌듯 SCC
// 좀 어려움
#include <iostream>
#include <stack>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAX = 301;
const int INF = 1000000007;
int id, N, M, d[MAX], sccNum[MAX];
bool finished[MAX];
vector<int> v[MAX];
vector<vector<int>> SCC;
stack<int> s;
vector<pair<int, int>> ans;
char map[MAX][MAX];
int dfs(int x) {
	d[x] = id++;
	s.push(x);

	int parent = d[x];
	for (auto i : v[x]) {
		if (d[i]==-1)
			parent = min(parent, dfs(i));
		else if (!finished[i])
			parent = min(parent, d[i]);
	}
	if (parent == d[x]) {
		vector<int> scc;
		int prev = -1;	// 이전 지점
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			sccNum[t] = SCC.size();
			if (prev!=-1) {
				ans.push_back({ prev, t });
			}
			// 이전 지점이 설정되지 않은 경우
			// 자기 자신과의 도로는 제외해야됨
			else if (t!=x && prev == -1) {
				ans.push_back({ x, t });
			}
			prev = t;	// 이전 지점 저장
			if (t == x)
				break;
		}
		SCC.push_back(scc);
	}
	return parent;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		// 초기화 (여러 번의 테스트 케이스)
		fill(finished, finished + MAX, false);
		fill(d, d + MAX, -1);
		fill(sccNum, sccNum + MAX, -1);
		for (auto& i : v)
			i.clear();
		for (auto& i : SCC) {
			i.clear();
		}
		ans.clear();
		SCC.clear();
		// 도시 개수 입력받음
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				// 자기 자신과의 도로는 넣으면 안됨
				// 플로이드를 위해서
				if (i == j)
					map[i][j] = '0';
			}
		}
		// 플로이드로 최소한의 도로만 넣도록 함 O(300^3)
		// i->k, k->j, i->j가 있을 경우 i->j는 필요 없음
		// 다시 되돌아올 필요가 없기 때문임
		// 그러면 SCC가 아닌가?
		for (int k = 0; k < N; k++) {
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					if (map[i][k] == '1' && map[k][j] == '1' && map[i][j] == '1') {
						map[i][j] = '0';
					}
				}
			}
		}
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] == '1') {
					v[i].push_back(j);
				}
			}
		}
		// 2->3, 3->2 이러한 도로 때문에 SCC 따져야됨
		for (int i = 0; i < N; i++) {
			if (d[i]==-1)
				dfs(i);
		}
		// 다른 SCC인 경우 다리를 하나 더 놓아줘야됨
		for (int i = 0; i < N; i++) {
			for (auto j : v[i]) {
				if (sccNum[i] != sccNum[j])
					ans.push_back({ i, j });
			}
		}
		cout << ans.size() << "\n";
		for (auto i : ans) {
			cout << i.first + 1 << " " << i.second + 1 << "\n";
		}
		cout << "\n";
	}
}