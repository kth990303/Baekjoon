// 211017 #2879 코딩은 예쁘게 Gold I
// greedy, impl
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
const int MAX = 1011;
const int INF = 0x3f3f3f3f;
const int LNF = 1e18;
const int MOD = 1e9 + 7;
int N, a[MAX], b[MAX], c[MAX], n[MAX];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < N; i++) {
		cin >> b[i];
		c[i] = b[i] - a[i];
	}
	int ans = 0;
	for (int i = 1, j = 0; i < N; i++, j++) {
		if (c[i] * c[j] <= 0)
			ans += abs(c[j]);
		else if (c[i] < 0 && c[i] >= c[j])
			ans += c[i] - c[j];
		else if (c[i] < 0 && c[i] < c[j])
			continue;
		else if (c[i] >= 0 && c[i] >= c[j])
			continue;
		else
			ans += c[j] - c[i];
	}
	cout << ans + abs(c[N - 1]) << "\n";
}