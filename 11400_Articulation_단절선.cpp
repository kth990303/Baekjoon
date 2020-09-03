// 200903 #11400 ������ Platinum V
// �������� ������ �˰���
// ������ �������� (Standard)
// O(V+E)
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 100001;
vector<int> v[MAX];
vector<pair<int, int>> ans;
int d[MAX];
int V, E, id;
int dfs(int x, int parent) {
	d[x] = ++id;
	int ret = d[x];
	// �������� ã�� ���̹Ƿ� ������ �˰������ �޸�
	// child(�ڽ� ���) ���� ������ ���� ���� ����
	for (auto i : v[x]) {
		// �θ𲨴� �Ʊ� ��
		if (i == parent)
			continue;
		// ���� �湮���� �ʾҴٸ�
		if (!d[i]) {
			// �ڽ��� ��忡�� Ž�� �������� �� �� �ִ���
			int prev = dfs(i, x);
			// �� �� ���ٸ� �� ���� ������
			if (prev > d[x])
				ans.push_back({ min(x, i), max(x, i) });
			// ������ִ� ��� �� ���� ���� ��
			ret = min(ret, prev);
		}
		// �湮�� �ߴٸ� ���� ���� ��� ����
		else
			ret = min(ret, d[i]);
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
			dfs(i, 0);
	}
	sort(ans.begin(), ans.end());
	cout << ans.size() << "\n";
	for (auto i : ans) {
		cout << i.first << " " << i.second << "\n";
	}
}