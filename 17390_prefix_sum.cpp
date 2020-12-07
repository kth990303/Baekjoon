// 201207 #17390 �̰� �� Ǯ��� ��! Silver III
// �⺻���� prefix_sum
// prefix_sum�� segtree�� ���̴� update�� ���ٴ� ��!
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 300001;
int N, Q, a[MAX], sum[MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> Q;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	sort(a + 1, a + N + 1);	// �񳻸����� ����, a[1]���� ����
	for (int i = 1; i <= N; i++) {
		sum[i] = sum[i - 1] + a[i];	// ������ �迭
	}
	while (Q--) {
		int s, e;
		cin >> s >> e;
		cout << sum[e] - sum[s - 1] << "\n";	// ������ �˰���
	}
}