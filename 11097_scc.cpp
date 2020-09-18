// 200918 #11097 ���� ��ȹ Platinum IV
// SCC�ε� SCC�ƴѵ� SCC
// �� �����
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
		int prev = -1;	// ���� ����
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			sccNum[t] = SCC.size();
			if (prev!=-1) {
				ans.push_back({ prev, t });
			}
			// ���� ������ �������� ���� ���
			// �ڱ� �ڽŰ��� ���δ� �����ؾߵ�
			else if (t!=x && prev == -1) {
				ans.push_back({ x, t });
			}
			prev = t;	// ���� ���� ����
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
		// �ʱ�ȭ (���� ���� �׽�Ʈ ���̽�)
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
		// ���� ���� �Է¹���
		cin >> N;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> map[i][j];
				// �ڱ� �ڽŰ��� ���δ� ������ �ȵ�
				// �÷��̵带 ���ؼ�
				if (i == j)
					map[i][j] = '0';
			}
		}
		// �÷��̵�� �ּ����� ���θ� �ֵ��� �� O(300^3)
		// i->k, k->j, i->j�� ���� ��� i->j�� �ʿ� ����
		// �ٽ� �ǵ��ƿ� �ʿ䰡 ���� ������
		// �׷��� SCC�� �ƴѰ�?
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
		// 2->3, 3->2 �̷��� ���� ������ SCC �����ߵ�
		for (int i = 0; i < N; i++) {
			if (d[i]==-1)
				dfs(i);
		}
		// �ٸ� SCC�� ��� �ٸ��� �ϳ� �� ������ߵ�
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