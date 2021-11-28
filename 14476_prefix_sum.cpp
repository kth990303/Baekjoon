// 211128 #14476 최대공약수 하나 빼기 Gold II
// gcd, prefix_sum
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
typedef pair<int, pi> pii;
typedef pair<ll, ll> pl;
typedef pair<ll, pl> pll;
const int MAX = 1000011;
const int INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int gcd(int a, int b) {
	int r = a % b;
	if (!r)return b;
	return gcd(b, r);
}
int N, a[MAX], L[MAX], R[MAX];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
	}
	for (int i = 1; i <= N; i++) {
		if (i == 1)L[i] = a[i];
		else L[i] = gcd(L[i - 1], a[i]);
	}
	for (int i = N; i >= 1; i--) {
		if (i == N)R[i] = a[i];
		else R[i] = gcd(R[i + 1], a[i]);
	}
	int ans = 0, num = 0, tmp = 0, cnt = 0;
	for (int i = 1; i <= N; i++) {
		if (i == 1) {
			tmp = R[2];
		}
		else if (i == N) {
			tmp = L[N - 1];
		}
		else {
			tmp = gcd(L[i - 1], R[i + 1]);
		}
		if (ans < tmp) {
			ans = tmp;
			num = a[i];
		}
		if (i != 1 && tmp == ans)
			cnt++;
	}
	if (cnt == N - 1) {
		cout << -1 << "\n";
		return 0;
	}
	cout << ans << " " << num << "\n";
}