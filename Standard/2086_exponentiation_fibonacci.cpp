// 211109 #2086 피보나치수의합 Gold I
// exponentiation_by_square
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#include <queue>
#include <cmath>
#include <stack>
#include <set>
#include <map>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
const int MAX = 100011;
const double INF = 0x3f3f3f3f;
const ll LNF = 1e16;
const int MOD = 1e9;
ll A, B, N = 2;
struct Matrix {
	vector<vector<ll>> v;
	Matrix() {
		v = vector<vector<ll>>(N, vector<ll>(N, 0));
	}
	Matrix operator*(const Matrix O) const {
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
	if (k == 1)return M;
	R = power(M, k / 2);
	R = R * R;
	if (k % 2)
		R = R * M;
	return R;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> A >> B;
	Matrix M, M1, M2;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (i == N - 1 && j == N - 1)
				M.v[i][j] = 0;
			else
				M.v[i][j] = 1;
		}
	}
	M1 = power(M, A);
	M2 = power(M, B + 1);
	cout << (M2.v[0][0] - M1.v[0][0] + MOD) % MOD;
}