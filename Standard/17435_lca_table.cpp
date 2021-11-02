// 201225 #17435 합성함수와 쿼리 Gold I
// LCA에 존재하는 sparse_table (lca_table) standard
// 시간복잡도 O(QlgN), 공간복잡도 O(MlgN)
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
	// 즉, 초기값은 d[i][0]
	for (int i = 1; i <= M; i++) {
		cin >> d[i][0];
	}
	// f(2^(j+1))(i)=f(2^j)(i)를 2^j번만큼 합성한 값.
	// 공간복잡도: M(정의역의 개수) * lgN(치역의 깊이)
	for (int j = 1; j < SIZE; j++) {
		for (int i = 1; i <= M; i++) {
			d[i][j] = d[d[i][j - 1]][j - 1];
		}
	}
	// 쿼리 진행 (Q번, lgN시간만큼 진행)
	cin >> Q;
	while (Q--) {
		int n, x;
		cin >> n >> x;
		// lca의 원리, 2의 제곱꼴이므로 bit 이용
		// f(11)(3)의 경우 f(8)(3)을 3번 합성하면 됨.
		// SIZE=ceil(lg2(MAX))이므로, SIZE-1부터 진행.
		for (int i = SIZE - 1; i >= 0; i--) {
			if (n >= (1 << i)) {
				// 남은 합성 횟수 계산
				n -= 1 << i;
				// 1<<i번 합성한 후의 함수값으로
				x = d[x][i];
			}
		}
		// x가 결국 함숫값이 됨.
		cout << x << "\n";
	}
}