// 210603 #1344 Ãà±¸ Gold IV
// dp (if only math, bruthforce -> complex impl
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 19;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
vector<int> prime = { 2,3,5,7,11,13,17 };
double A, B, d[MAX][MAX][MAX];
double dp(int a, int b, int cur) {
	if (cur == 18) {
		if (binary_search(all(prime), a) 
			|| binary_search(all(prime), b))
			return 1;
		return 0;
	}
	double& ret = d[a][b][cur];
	if (ret != -1)
		return ret;
	ret = 0;
	ret += dp(a + 1, b, cur + 1) * A * (1 - B);
	ret += dp(a, b + 1, cur + 1) * (1 - A) * B;
	ret += dp(a + 1, b + 1, cur + 1) * A * B;
	ret += dp(a, b, cur + 1) * (1 - A) * (1 - B);
	return ret;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cout << fixed;
	cout.precision(16);
	cin >> A >> B;
	A /= 100; B /= 100;
	fill(&d[0][0][0], &d[MAX - 1][MAX - 1][MAX], -1.0);
	cout << dp(0, 0, 0) << "\n";
}