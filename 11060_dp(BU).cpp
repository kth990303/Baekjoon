// 200919 #11060 ���� ���� Silver II
// O(N^2)
// ���������� �� ������ ž�ٿ��� �ξ� �����
#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 1001;
const int INF = 1000000007;
int N, a[MAX], d[MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	fill(d, d + N, -1);
	d[0] = 0;
	for (int i = 0; i < N - 1; i++) {
		// -1�� ��� �� �� ���� ĭ
		if (d[i] == -1)
			continue;
		for (int j = 1; j <= a[i]; j++) {
			// ���� üũ
			if (i + j < N) {
				// ���� �湮���� ���� ���̸�
				if (d[i + j] == -1)
					d[i + j] = d[i] + 1;
				// �̹� �湮�� ���̸� �� ª�� �Ÿ���
				else
					d[i + j] = min(d[i + j], d[i] + 1);
			}
		}
	}
	cout << d[N - 1];
}