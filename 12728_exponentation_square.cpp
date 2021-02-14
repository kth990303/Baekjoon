// 210214 #12728, #12925 Numbers Platinum I
// Platinum I ~ Diamond V
// exponentation_square, Number of Theory
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef long long ll;
const int MOD = 1000;
ll N = 2, B;
// matrix exponentation_sqaure(o(logn))
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

	int t;
	cin >> t;
	for (int i = 1; i <= t; i++) {
		cout << "Case #" << i << ": ";
		ll n;
		cin >> n;
		string ans;
		Matrix A;
		// like pibonacci
		A.v[0][0] = 6; A.v[0][1] = -4;
		A.v[1][0] = 1; A.v[1][1] = 0;
		A = power(A, n - 1);
		ll num = A.v[1][0] * 28 + A.v[1][1] * 6;
		// % 1000, + 1000 % 1000
		ans = to_string(((num - 1) % MOD + MOD )% MOD);
		for (int j = 0; j < 3 - ans.length(); j++) {
			cout << "0";
		}
		cout << ans << "\n";
	}
}