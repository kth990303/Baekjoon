// 210922 #20501 Facebook Gold II
// bitset
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
#include <bitset>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<int, pi> pii;
const int MAX = 2001;
const int INF = 0x3f3f3f3f;
int N, Q;
bitset<MAX> b[MAX];
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		string s;
		cin >> s;
		for (int j = 0; j < N; j++) {
			b[i][j] = s[j] - '0';
		}
	}
	cin >> Q;
	while (Q--) {
		int u, v;
		cin >> u >> v;
		u--; v--;
		cout << (b[u] & b[v]).count() << "\n";
	}
}