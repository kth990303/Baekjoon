// 211002 #6443 애너그램 Gold IV
// I think it's Silver II
// backtracking -> next_permutation
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
const int MAX = 21;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
int N;
string s;
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	while (N--) {
		cin >> s;
		sort(all(s));
		do {
			cout << s << "\n";
		} while (next_permutation(all(s)));
	}
}