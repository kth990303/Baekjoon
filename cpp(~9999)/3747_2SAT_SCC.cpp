// 200828 #3747 �Ϻ��� ���� Platinum IV
// �亯�� �ʹ����� 2-SAT������ �������� 2-SAT
// 2-SAT �����ϱ� ���ϵ�
// �������� Ǯ� ���� ���� ������,
// 1. MAX ũ�� 2. EOF 3. �ʱ�ȭ �� ���ֱ�!
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
const int MAX = 2002;	// �̰� �������� 2���...
using namespace std;
int N, M, id, d[MAX], ans[MAX];
bool finished[MAX];
vector<int> v[MAX];
vector<vector<int>> SCC;
stack<int> s;
int f(int a) {
	return a > N ? a - N : a + N;
}
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
			ans[t] = SCC.size() + 1;
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

	while (cin >> N >> M) {
		id = 0;
		fill(d, d + MAX, 0);
		fill(ans, ans + MAX, 0);
		fill(finished, finished + MAX, false);
		for (auto& i : v)
			i.clear();
		SCC.clear();
		for (int i = 0; i < M; i++) {
			int a, b;
			cin >> a >> b;
			// ����: ~�缱
			if (a < 0) a = -a + N;
			if (b < 0)b = -b + N;
			// ~A -> B , ~B->A
			v[f(a)].push_back(b);
			v[f(b)].push_back(a);
		}
		for (int i = 1; i <= N; i++) {
			if (!d[i])
				dfs(i);
		}
		bool flag = true;
		for (int i = 1; i <= N; i++) {
			if (ans[i] == ans[i + N])
				flag = false;
		}
		if (!flag)
			cout << "0\n";
		else
			cout << "1\n";
	}
}