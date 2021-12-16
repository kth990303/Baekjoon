// 211216 #23815 ¶Ë°ÔÀÓ Gold IV
// cannot top-down -> bottom-up
// use calculator function
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
const int MAX = 100011;
const int INF = 0x3f3f3f3f;
const ll LNF = 0x3f3f3f3f3f3f3f3f;
const int MOD = 1e9 + 7;
int N, d[MAX][2], a[MAX][2];
char ch[MAX][2];
int f(int cur, char op, int x) {
	if (op == '+')return cur + x;
	if (op == '-')return cur - x;
	if (op == '*')return cur * x;
	return cur / x;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < 2; j++) {
			string s;
			cin >> s;
			ch[i][j] = s[0];
			a[i][j] = s[1] - '0';
		}
	}
	d[0][0] = d[0][1] = 1;
	for (int i = 1; i <= N; i++) {
		for (int k = 0; k < 2; k++) {
			int ret = d[i - 1][k];
			if (ret <= 0)continue;
			int tmp[2] = { f(ret, ch[i][0],a[i][0]), f(ret, ch[i][1],a[i][1]) };
			int M = max(tmp[0], tmp[1]);
			if (!k)
				d[i][0] = max(tmp[0], tmp[1]);
			else if (i == 1)
				d[i][1] = 1;
			else
				d[i][1] = max(d[i - 1][0], max(tmp[0], tmp[1]));
		}
	}
	int ans = max(d[N][0], d[N][1]);
	if (ans <= 0)cout << "ddong game";
	else cout << ans;
}