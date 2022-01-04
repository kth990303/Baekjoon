// 220105 #15311 æ‡∆»±‚ Platinum V
// 1000a+b (0<=a,b<=1000)
// math, constructive
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
const ll LNF = 1e16;
const int MOD = 1e9 + 7;
int N, K;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	cout << 2000 << "\n";
	for (int i = 1; i <= 2000; i++) {
		if (i <= 1000)
			cout << 1 << " ";
		else
			cout << 1000 << " ";
	}
}