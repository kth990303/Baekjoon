// Çà·Ä°ö¼À ½´µµÄÚµå ÀÌ¿ë (by kks227's pseudo code)
// 210105 #10830 Çà·Ä Á¦°ö Gold III
// exponentiation_squaring
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;
const int MOD = 1000;
ll N, B;
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
			return R;
		}
	}
	if (k == 1)
		return M;
	Matrix R = power(M, k / 2);
	R = R * R;
	if (k % 2)
		R = R * M;
	return R;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N >> B;
	Matrix A;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> A.v[i][j];
		}
	}
	A = power(A, B);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << A.v[i][j] % MOD << " ";
		}
		cout << "\n";
	}
}