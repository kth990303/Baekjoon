// 220101 #24040 Good Bye BOJ 2021! B¹ø
// adhoc, number_theory
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
const int MAX = 1e8;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e16;
const int MOD = 1e9 + 7;
ll t, N;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> t;
	while (t--) {
		cin >> N;
		if (N%9==0 || N % 3 == 2) {
			cout << "TAK\n";
			continue;
		}
		else cout << "NIE\n";
	}
}