// 200912 #15271 ģ�� �Ӹ����2 Platinum V
// �̺� ��Ī
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAX = 201;
int N, M, d[MAX];
bool used[MAX];
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
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		// �ٸ� ������ ��쿡�� ��Ī
		if (a % 2 != b % 2) {
			// a�� ������ ���� ���ڷ� �ٲ�����
			if (!(a % 2))
				swap(a, b);
			// ���� -> ���� ��Ī
			v[a].push_back(b);
		}
	}
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		fill(used, used + MAX, false);
		// ¦�� ���������� 2�� ��� ���� �� ����
		if (dfs(i))
			ans += 2;
	}
	// ��� ¦�������� ���� ��� ȥ�� ���ߴ� �� ����
	if (ans != N)
		ans++;
	cout << ans << "\n";
}