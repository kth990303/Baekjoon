// 210105 #14289 본대산책3 Gold I
// exponentiation_square, recursion_matrix
// graph_Matrix
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;
ll N, M, D;
// Matrix exponentiation_square pseudo code
class Matrix {
public:
	vector<vector<ll>> v;
	Matrix() {
		v = vector<vector<ll>>(N, vector<ll>(N, 0));
	}
	Matrix operator*(const Matrix O) {
		Matrix R;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					R.v[i][j] += v[i][k] * O.v[k][j];
					R.v[i][j] %= MOD;
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
		}
		return R;
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

	cin >> N >> M;
	Matrix A;
	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		A.v[a][b] = A.v[b][a] = 1;
	}
	cin >> D;
	cout << power(A, D).v[0][0] % MOD << "\n";
}