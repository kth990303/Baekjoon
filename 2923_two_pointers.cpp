// 211008 #2923 숫자게임 Platinum V
// two_pointers O(N*100)
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
typedef pair<pi, int> pii;
const int MAX = 101;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
int N, M1, m1 = 100, M2, m2 = 100;
vector<int> a(101), b(101), tmpA(101), tmpB(101);
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 1; i <= N; i++) {
		int n1, n2, n = i;
		cin >> n1 >> n2;
		a[n1]++; b[n2]++;
		M1 = max(M1, n1); M2 = max(M2, n2);
		m1 = min(m1, n1); m2 = min(m2, n2);
		tmpA = a, tmpB = b;
		int s = m1, e = M2, ans = 0;
		while (1) {
			if (e<m2 || s>M1)
				break;
			if (!tmpA[s]) {
				s++;
				continue;
			}
			if (!tmpB[e]) {
				e--;
				continue;
			}
			if (tmpA[s] < tmpB[e]) {
				ans = max(ans, s + e);
				tmpB[e] -= tmpA[s];
				s++;
			}
			else {
				ans = max(ans, s + e);
				tmpA[s] -= tmpB[e];
				e--;
			}
		}
		cout << ans << "\n";
	}
	
}