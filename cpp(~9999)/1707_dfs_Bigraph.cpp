// 200906 #1707 �̺б׷��� Gold IV
// �̺� �׷��� (Bipartite Graph) ��������
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int MAX = 20001;
vector<int> v[MAX];
int V, E;
int color[MAX];
// dfs�� �ڽ��� ���� �ݴ�Ǵ� ���� ĥ���ش�
bool dfs(int x, int num) {
	color[x] = num;
	// ������ִ� ���� Ȯ��
	for (auto i : v[x]) {
		// ���� �����̸� false ����
		if (color[i] == num) {
			return false;
		}
		// ���� �湮 ���� ���
		else if (!color[i]) {
			color[i] = -num;
			// �̰� false�� ��� ������ false �����ϰ�
			if (!dfs(i, -num))
				return false;
		}
	}
	return true;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	int t;
	cin >> t;
	while (t--) {
		cin >> V >> E;
		for (auto& i : v)
			i.clear();
		fill(color, color + MAX, 0);
		// No: 0, Red: 1, Blue: -1
		for (int i = 0; i < E; i++) {
			int a, b;
			cin >> a >> b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		bool biGraph = true;
		for (int i = 1; i <= V; i++) {
			if (!color[i]) {
				if (!dfs(i, 1)) {
					cout << "NO\n";
					biGraph = false;
					break;
				}
			}
		}
		if (biGraph) {
			cout << "YES\n";
		}
	}
}