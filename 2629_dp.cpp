// 211001 #2629 ¾çÆÈÀú¿ï Gold II
// Why G2? I think it's G4~G3
// knapsack dp
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
// it can be abs(num) -> +weight, -weight -> 2*N cnts
const int MAX = 63;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
int N, M, a[MAX], d[MAX][40003];
int dp(int cur, int val) {
	if (cur > N * 2 || val < 0)
		return 0;
	if (!val)
		return 1;
	int& ret = d[cur][val];
	if (ret != -1)
		return ret;
	ret = max(dp(cur + 1, val), dp(cur + 1, val + a[cur]));
	return ret;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		a[i + N] = -a[i];
	}
	memset(d, -1, sizeof(d));
	cin >> M;
	while (M--) {
		int n;
		cin >> n;
		cout << (dp(0, n) ? "Y " : "N ");
	}
}