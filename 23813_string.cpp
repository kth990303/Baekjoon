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
typedef pair<ll, ll> pl;
const int MAX = 100011;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e16;
const int MOD = 1e9 + 7;
ll ans, N;
string s, t;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> s;
	N = s.length();
	t = s;
	do {
		ans += stoll(t);
		t = t[N - 1] + t.substr(0, N - 1);
	} while (t != s);
	cout << ans;
}