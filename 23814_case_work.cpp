#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <string>
#include <unordered_map>
#include <unordered_set>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 100011;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e16;
const int MOD = 1e9 + 7;
ll D, N, M, K, sum, ans;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> D >> N >> M >> K;
	sum = N / D + M / D + K / D;
	ll tmpsum = N / D + M / D;
	ans = K;
	N = D - (N % D);
	M = D - (M % D);
	ll tmp = K % D;
	ll m = min(N, M);
	if (m <= tmp) {
		tmp -= m;
		sum++;
		ans -= m;
	}
	m = max(N, M);
	if (m <= tmp) {
		tmp -= m;
		sum++;
		ans -= m;
	}
	if ((K - (N + M)) / D + tmpsum + 2 > sum) {
		ans = K - (N + M);
	}
	cout << ans;
}