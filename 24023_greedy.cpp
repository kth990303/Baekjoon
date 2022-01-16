// 220116 #24023 ¾Æ±âÈ«À± Gold V
// greedy, bitmask or operator O(N)
// another solution: two_pointers
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
#include <cstring>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 200011;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int N, K, M;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N >> K;
	int s = 1;
	for (int i = 1; i <= N; i++) {
		int x;
		cin >> x;
		if ((~K) & x) {
			s = i + 1;
			M = 0;
			continue;
		}
		M |= x;
		if (M == K) {
			cout << s << " " << i;
			return 0;
		}
	}
	cout << -1;
}