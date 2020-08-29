// 200829 #2188 ��� ���� Platinum IV
// �̺и�Ī�� �⺻ �� �⺻
// ���������� �⺻�� ��5���ε�... �̺и�Ī�� ��4�� ����� ���ֳ���
#include <iostream>
#include <vector>
const int MAX = 201;
using namespace std;
int N, M, d[MAX];
bool used[MAX];
vector<int> v[MAX];
bool dfs(int x) {
	for (auto i : v[x]) {
		// ������ ���� ������ ����� �� �� false
		// �� ���� �̹� �Ű��� ���.
		// ������ ���� ������ ��� �ƴϸ� ���̻� �ȿű�
		if (used[i])
			continue;
		used[i] = true;
		// !d[i]: ���� ������ ���� ���� ���
		// dfs(d[i])�� true�� ��� ���� ������ �ְ� �ٸ� ������ �̵��ż� ��� �� ���
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
	int ans = 0;
	for (int i = 1; i <= N; i++) {
		// ���� ��Ī�� ���� ���� ��Ī�� �ǵ帱 �� �����ϱ�
		fill(used, used + MAX, false);
		// ��Ī�� �Ǹ� ans++
		if (dfs(i))
			ans++;
	}
	// ��Ī�� ��
	cout << ans << "\n";
}
