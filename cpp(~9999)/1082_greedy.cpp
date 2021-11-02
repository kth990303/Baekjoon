// 210612 #1082 ¹æ¹øÈ£ Gold IV
// greedy
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 51;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int N, M, d[MAX][MAX], C1 = INF, C2 = INF, len;
vector<int> v;
string ans;
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
		C1 = min(C1, v[i]);
		if (i > 0)
			C2 = min(C2, v[i]);
	}
	cin >> M;
	if (M < C2) {
		cout << 0 << "\n";
		return 0;
	}
	len = 1 + (M - C2) / C1;
	for (int i = len - 1; i >= 0; i--) {
		for (int j = N - 1; j >= 0; j--) {
			if (M - v[j] >= C1 * i) {
				ans += to_string(j);
				M -= v[j];
				break;
			}
		}
	}
	cout << ans << "\n";
}