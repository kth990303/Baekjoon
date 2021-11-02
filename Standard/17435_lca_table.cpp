// 201225 #17435 �ռ��Լ��� ���� Gold I
// LCA�� �����ϴ� sparse_table (lca_table) standard
// �ð����⵵ O(QlgN), �������⵵ O(MlgN)
#include <iostream>
#include <cmath>
using namespace std;
const int MAX = 500001;
const int SIZE = 19;	// ceil(log2(MAX))
int M, Q, d[MAX][SIZE];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> M;
	// d[i][j]: f(2^j)(i)
	// ��, �ʱⰪ�� d[i][0]
	for (int i = 1; i <= M; i++) {
		cin >> d[i][0];
	}
	// f(2^(j+1))(i)=f(2^j)(i)�� 2^j����ŭ �ռ��� ��.
	// �������⵵: M(���ǿ��� ����) * lgN(ġ���� ����)
	for (int j = 1; j < SIZE; j++) {
		for (int i = 1; i <= M; i++) {
			d[i][j] = d[d[i][j - 1]][j - 1];
		}
	}
	// ���� ���� (Q��, lgN�ð���ŭ ����)
	cin >> Q;
	while (Q--) {
		int n, x;
		cin >> n >> x;
		// lca�� ����, 2�� �������̹Ƿ� bit �̿�
		// f(11)(3)�� ��� f(8)(3)�� 3�� �ռ��ϸ� ��.
		// SIZE=ceil(lg2(MAX))�̹Ƿ�, SIZE-1���� ����.
		for (int i = SIZE - 1; i >= 0; i--) {
			if (n >= (1 << i)) {
				// ���� �ռ� Ƚ�� ���
				n -= 1 << i;
				// 1<<i�� �ռ��� ���� �Լ�������
				x = d[x][i];
			}
		}
		// x�� �ᱹ �Լ����� ��.
		cout << x << "\n";
	}
}