// 200826 2-SAT Algorithm Platinum IV
// SCC + �̻���� ������ ��
// ������ 2-SAT�� �̹�� ��� ����
#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
using namespace std;
int N, M, id, d[20002], ans[20002];
vector<int> v[20002];
vector<vector<int>> SCC;
bool finished[20002];
stack<int> s;
int f(int a) {
	// f �� �ϴ� ��:
	// not(����): -1~-4 -> ������ ������ ����� ����
	// (���): 1~4 -> ����� �������� ����� N���� ũ��
	// ���: ~a: 1234 a: 5678
	return a > N ? a - N : a + N;
}
int dfs(int x) {
	d[x] = ++id;
	s.push(x);

	int parent = d[x];
	for (auto i : v[x]) {
		// ���� dfs�� ���� Ȯ������ �ʾ�����
		if (!d[i])
			parent = min(parent, dfs(i));
		// ���� scc�� ������ �ȵ�����
		else if (!finished[i])
			parent = min(parent, d[i]);
	}
	// dfs�ߴ��� �θ� ���� scc�� �̷����ٸ�
	if (parent == d[x]) {
		vector<int> scc;
		while (1) {
			int t = s.top();
			s.pop();
			scc.push_back(t);
			// ��������� scc�� ���� �Ϸ�������
			finished[t] = true;
			// scc Num�� 1����
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

	cin >> N >> M;
	while (M--) {
		int a, b;
		cin >> a >> b;
		// not �� ��� N+1 ~ N+N
		if (a < 0)
			a = -a + N;
		if (b < 0)
			b = -b + N;
		// f�� �ִ� ����: not ������
		v[f(a)].push_back(b); // ~A -> B 
		v[f(b)].push_back(a); // ~B -> A
	}
	// not ���� 2*N��
	// �׷����� �𵨸�������
	for (int i = 1; i <= 2 * N; i++) {
		if (!d[i])
			dfs(i);
	}
	// ���� SCC�� 
	// ~A -> A ���� ����� �����Ѵٸ�,
	for (int i = 1; i <= N; i++) {
		if (ans[i] == ans[i + N]) {
			cout << "0";
			return 0;
		}
	}
	cout << "1";
}