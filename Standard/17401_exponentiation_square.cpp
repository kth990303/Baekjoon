// 211016 #17401 일하는세포 Platinum V
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
const int MAX = 101;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const ll MOD = 1e9 + 7;
int T, N, D;
class Matrix {
public:
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

	cin >> T >> N >> D;
	Matrix M[MAX];
	for (int i = 0; i < N; i++) {
		M[0].v[i][i] = 1;
	}
	for (int i = 1; i <= T; i++) {
		int t;
		cin >> t;
		while (t--) {
			ll a, b, cost;
			cin >> a >> b >> cost;
			a--; b--;
			M[i].v[a][b] = cost;
		}
	}
	for (int i = 1; i <= T; i++) {
		M[0] = M[0] * M[i];
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << M[0].v[i][j] << " ";
		}
		cout << "\n";
	}
	M[0] = power(M[0], 1LL*D / T);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << M[0].v[i][j] << " ";
		}
		cout << "\n";
	}
	for (int i = 1; i <= D % T; i++)
		M[0] = M[0] * M[i];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cout << M[0].v[i][j] << " ";
		}
		cout << "\n";
	}
}