// 200829 #11376 ������ȣ2 Platinum IV
// Bipartite�� ������ ��������
// ������ ���� 2������ ���� -> dfs�� �� ��
#include <iostream>
#include <vector>
const int MAX = 1001;
using namespace std;
bool used[MAX];
int N, M, ans, d[MAX];
vector<int> v[MAX];
bool dfs(int x) {
	for (auto i : v[x]) {
		if (used[i])
			continue;
		used[i] = true;
		if (!d[i] || dfs(d[i])) {
			d[i] = x;
			return true;
		}
	}
	return false;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		int num;
		cin >> num;
		while (num--) {
			int j;
			cin >> j;
			v[i].push_back(j);
		}
	}
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= 2; j++) {
			fill(used, used + MAX, false);
			if (dfs(i))
				ans++;
		}	
	}
	cout << ans << "\n";
}