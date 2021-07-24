// 210724 #17943 도미노예측 Gold IV
// bitmask + prefix_sum
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <vector>
#include <cmath>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 200001;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
int N, Q, a[MAX], p[MAX];
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> Q;
	for (int i = 1; i <= N - 1; i++) {
		cin >> a[i];
		p[i] = p[i - 1] ^ a[i];
	}
	while (Q--) {
		int ch, x, y, d;
		cin >> ch;
		if (!ch) {
			cin >> x >> y;
			cout << (p[x - 1] ^ p[y - 1]) << "\n";
		}
		else {
			cin >> x >> y >> d;
			cout << (p[x - 1] ^ p[y - 1] ^ d) << "\n";
		}
	}
}