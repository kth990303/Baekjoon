// 210226 #2099 The game of death Gold II
// exponentation_by_square: 인접행렬과 그래프
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;
const int MAX = 1000001;
ll N, K, M;
class Matrix {
public:
	vector<vector<int>> v;
	Matrix() {
		v = vector<vector<int>>(N, vector<int>(N, 0));
	}
	Matrix operator *(const Matrix O) const {
		Matrix R;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					R.v[i][j] += v[i][k] * O.v[k][j];
				}
			}
		}
		return R;
	}
};
Matrix power(Matrix M, ll k) {
	Matrix R;
	if (!k) {
		for (int i = 0; i < N; i++) {
			R.v[i][i] = 1;
			return R;
		}
	}
	if (k == 1)
		return M;
	R = power(M, k / 2);
	R = R * R;
	if (k % 2)
		R = R * M;
	return R;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> K >> M;
	Matrix A;
	for (int i = 0; i < N; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		A.v[i][a] = 1;
		A.v[i][b] = 1;
	}
	A=power(A, K);
	while (M--) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		if (A.v[a][b])
			cout << "death\n";
		else
			cout << "life\n";
	}
}