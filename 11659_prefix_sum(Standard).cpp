// #11659 ���� �� ���ϱ�4 Silver III
// ���� �� N��, ���� ���� ���϶�� ���� M��
// O(NM): �ʹ� �����ɸ�
// prefix_sum�� �̿��ϸ� O(M)
#include <iostream>
using namespace std;
int d[100001];
int s[100001];
int main() {
	cin.tie(nullptr);
	ios_base::sync_with_stdio(false);

	int n, m;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> d[i];
	}
	// ������ �迭�� ���� �����Ѵ�
	// s[1]=d[1], s[2]=s[1]+d[2], ...
	for (int i = 1; i <= n; i++) {
		s[i] = s[i - 1] + d[i];
	}
	// query
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		cout << s[b] - s[a - 1] << "\n";
	}
}