// 211012 #16467 병아리의변신은무죄 Gold I
// exponentiation_square
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
const int MAX = 300011;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const ll MOD = 1e8 + 7;
int t, K, N;
class Matrix {
public:
	vector<vector<ll>> v;
	Matrix() {
		v = vector<vector<ll>>(K + 2, vector<ll>(K + 2, 0));
	}
	Matrix operator*(const Matrix O) const {
		Matrix R;
		for (int i = 0; i < K + 2; i++) {
			for (int j = 0; j < K + 2; j++) {
				for (int k = 0; k < K + 2; k++) {
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
		for (int i = 0; i < K + 2; i++) {
			R.v[i][i] = 1;
			return R;
		}
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

	cin >> t;
	while (t--) {
		cin >> K >> N;
		Matrix A;
		for (int i = 0; i < K + 2; i++) {
			for (int j = 0; j < K + 2; j++) {
				if (i - j == 1)
					A.v[i][j] = 1;
				else
					A.v[i][j] = 0;
			}
		}
		A.v[0][0] += 1;
		A.v[0][K] += 1;
		A = power(A, 1LL*N - 1);
		cout << (A.v[0][0] + A.v[K][0]) % MOD << "\n";
	}
}