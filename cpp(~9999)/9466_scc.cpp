// 201225 #9466 �� ������Ʈ Gold IV
// SCC�� ���ϴ� ����. �ٸ�, SCC�� ������ �ʿ� ���� �ܼ� dfs�ε� ���� ����
// SCC Ǯ�� O(N) : O(V+E)�̹Ƿ�
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
const int MAX = 100001;
using namespace std;
vector<int> v[MAX];
vector<vector<int>> SCC;
int id, d[MAX];
bool finished[MAX];
stack<int> s;
int N, ans;
int dfs(int x) {
	// ���⼭�� id�� �ʿ����� �ʴ�.
	// scc ������ �� �ʿ䰡 �����Ƿ�
	d[x] = ++id;
	// ���ÿ� �־ scc�� �־�����
	s.push(x);

	int parent = d[x];
	for (auto i : v[x]) {
		// ���� �湮���� �ʾ�����
		if (!d[i])
			parent = min(parent, dfs(i));
		// �湮�ߴµ�, �̹� �ϰ�� ��尡 �ƴ϶��
		else if (!finished[i])
			parent = min(parent, d[i]);
	}
	// ����Ŭ�� �����ƴٸ�
	if (parent == d[x]) {
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			// �ϰ�� ���� ����
			finished[t] = true;
			if (t == x)
				break;
		}
		// scc����� 1�� ���, �ڱ� �ڽ��̾�߸� �Ѵ�.
		if (scc.size() > 1 || v[scc[0]][0] == scc[0])
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
		// �ʱ�ȭ �۾�
		for (auto& i : v)
			i.clear();
		SCC.clear();
		id = 0, ans = 0;
		fill(d, d + MAX, 0);
		fill(finished, finished + MAX, false);
		while (!s.empty())
			s.pop();

		cin >> N;
		for (int i = 1; i <= N; i++) {
			int k;
			cin >> k;
			// i��° �ִ� k��°�� ���� �ǰ� �;���.
			// �ܹ��� �׷���
			v[i].push_back(k);
		}
		for (int i = 1; i <= N; i++) {
			// ���� Ž���� �������� Ž�� ����
			if (!d[i])
				dfs(i);
		}
		// �� ����Ŭ(��)�� �ִ� ���� �� �����ֱ�
		for (int i = 0; i < SCC.size(); i++) {
			ans += SCC[i].size();
		}
		cout << N - ans << "\n";
	}
}