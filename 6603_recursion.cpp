// 201212 #6603 �ζ� Silver II
// ���, ��Ʈ��ŷ �Լ����� 2�� Ǯ��
// �Լ� ���ڰ� 2���� ���� for���� ����.
#include <iostream>
#include <vector>
using namespace std;
int a[13], N;
vector<int> v;
void dfs(int num, int cnt) {
	// for���� ���� ���, �迭 ���� üũ�ϱ�
	if (cnt == N + 1)
		return;
	if (num == 6) {
		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << " ";
		}
		cout << "\n";
		return;
	}
	// �����ϰ�
	v.push_back(a[cnt]);
	dfs(num + 1, cnt + 1);
	v.pop_back();
	// ���� ���ϰ�
	dfs(num, cnt + 1);
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	while (cin >> N) {
		if (!N)
			break;
		for (int i = 0; i < N; i++)
			cin >> a[i];
		dfs(0, 0);
		cout << "\n";
	}
}