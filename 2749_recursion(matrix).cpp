// 행렬곱셈 슈도코드(kks227님의 슈도코드로 공부) 이용
// 210105 #2749 피보나치 수3 Gold II
// matrix, exponentiation_by_squaring
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int MOD = 1000000;
ll n, B, N = 2;
// Matrix pseudo code
class Matrix {
public:
	vector<vector<ll>> v;
	// Constructor
	Matrix() {
		v = vector<vector<ll>>(N, vector<ll>(N, 0));
	}
	// operator overiding
	Matrix operator*(const Matrix O) {
		Matrix R;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				for (int k = 0; k < N; k++) {
					// i-j i-k k-j
					R.v[i][j] += (v[i][k] * O.v[k][j]) % MOD;
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

	cin >> n;
	Matrix A;
	// [fk fk-1]=[1 1 1 0][fk-1 fk-2]
	// [fk fk-1]=[1 1 1 0]^k-1[f1 f0]
	A.v[0][0] = 1, A.v[0][1] = 1, A.v[1][0] = 1;
	A = power(A, n - 1);
	// fk=A.v[0][0] (matrix *)
	cout << A.v[0][0] % MOD << "\n";
}