// 200829 #4013 ATM Platinum II
// SCC ��, ���� ����Ͽ� SCC���� �������� �� �غ��� ����
// ȣ���� ��� �ϳ� �����
// 2�ð��� ������
// ������ ������ ó������ �� ®����, ������ �߸���
// ����(kks227)�� ��α� ������
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <vector>
const int MAX = 500001;
const int DNF = 1000000007;
using namespace std;
int N, M, id, d[MAX], w[MAX], sccNum[MAX];
bool finished[MAX], isEat[MAX];
vector<int> v[MAX];
vector<vector<int>> SCC;
stack<int> s;
// �������� ����
int sccW[MAX], in[MAX];	// scc �� ��, indegree
vector<int> adj[MAX];	
bool sccHasEat[MAX];
bool can[MAX];
int ans[MAX];
int dfs(int x) {
	d[x] = ++id;
	s.push(x);
	
	int parent = d[x];
	for (auto i : v[x]) {
		if (!d[i])
			parent = min(parent, dfs(i));
		else if (!finished[i])
			parent = min(parent, d[i]);
	}
	if (parent == d[x]) {
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			finished[t] = true;
			sccNum[t] = SCC.size() + 1;
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

	cin >> N >> M;
	while (M--) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}
	// SCC �����
	for (int i = 1; i <= N; i++) {
		if (!d[i])
			dfs(i);
	}
	// �� ���� �Է�
	for (int i = 1; i <= N; i++) {
		cin >> w[i];
	}
	int s, k;
	cin >> s >> k;
	// ������� ���� �Է� (������ ��� ���� ����)
	for (int i = 1; i <= k; i++) {
		int num;
		cin >> num;
		isEat[num] = true;
	}
	// ���� �Է� ��.
	for (int i = 1; i <= N; i++) {
		sccW[sccNum[i]] += w[i];
		// scc�� ��� ������ ������ �ִ°�?
		if (s == i)
			s = sccNum[i];
		// scc�� ��������� ������ �ִ°�?
		if (isEat[i])
			sccHasEat[sccNum[i]] = true;

		for (int next : v[i]) {
			if (sccNum[next] == sccNum[i])
				continue;
			// scc�� �ٸ� ��� ���� scc �־���
			adj[sccNum[i]].push_back(sccNum[next]);
			// ���������� ���� ����
			in[sccNum[next]]++;
		}
	}
	int res = 0;
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		w[i] = sccW[i];	// scc �׼���ŭ �ʱ�ȭ
		if (i == s)
			can[i] = true;
		if (!in[i])
			q.push(i);
	}
	// SCC ���� ��������
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (auto i : adj[x]) {
			if (can[x]) {
				w[i] = max(w[i], w[x] + sccW[i]);
				can[i] = true;
			}
			in[i]--;
			if (!in[i])
				q.push(i);
		}
	}
	for (int i = 1; i <= SCC.size(); i++) {
		if (sccHasEat[i] && can[i])
			res = max(res, w[i]);
	}
	cout << res << "\n";
}