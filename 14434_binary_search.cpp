// 211005 #14434 ³îÀÌ±â±¸1 Gold I
// binary_Search
// upper_bound return idx => height
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
const int MAX = 200011;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
int N, M, K, Q, p[MAX], ans[MAX];
vector<int> toy, v[MAX];
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M >> K >> Q;
	toy.resize(M + 1);
	for (int i = 1; i <= M; i++) {
		cin >> toy[i];
	}
	for (int i = 1; i <= K; i++) {
		int n;
		cin >> n;
		v[n].push_back(i);
	}
	while (Q--) {
		int i, j, k;
		cin >> i >> j >> k;
		k = toy[k];
		int s = 1, e = MAX, res = MAX;
		while (s <= e) {
			int mid = (s + e) / 2;
			int n1 = upper_bound(all(v[i]), mid) - v[i].begin();
			int n2 = upper_bound(all(v[j]), mid) - v[j].begin();
			if (n1 + n2 >= k) {
				res = mid;
				e = mid - 1;
			}
			else
				s = mid + 1;
		}
		p[res]++;
	}
	for (int i = 1; i <= K; i++) {
		ans[i] = ans[i - 1] + p[i];
	}
	for (int i = 1; i <= K; i++) {
		cout << ans[i] << "\n";
	}
}