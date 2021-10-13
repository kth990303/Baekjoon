// 211013 #2339 석판자르기 Gold I
// divide_conquer, recursion
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
typedef pair<ll, ll> pl;
const int MAX = 22;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e16;
const ll MOD = 1e9 + 7;
int N, a[MAX][MAX], ans;
vector<pi> v;
int check(int x1, int y1, int x2, int y2) {
	int n1 = 0, n2 = 0;
	for (int i = y1; i < y2; i++) {
		for (int j = x1; j < x2; j++) {
			if (a[i][j] == 1)
				n1++;
			else if (a[i][j] == 2)
				n2++;
		}
	}
	if (n2 == 1 && !n1)
		return 1;
	if (!n2)
		return 0;
	return 2;
}
int solve(int x1, int y1, int x2, int y2, int dir) {
	int n = check(x1, y1, x2, y2);
	if (n <= 1)
		return n;
	int ret = 0;	
	for (int i = y1; i < y2; i++) {
		for (int j = x1; j < x2; j++) {
			if (a[i][j] == 1) {
				bool flag = true;
				if (!dir) {
					for (int k = y1; k < y2; k++) {
						if (a[k][j] == 2) {
							flag = false;
							break;
						}
					}
					if (flag) {
						ret += solve(x1, y1, j, y2, 1)
							* solve(j + 1, y1, x2, y2, 1);
					}
				}
				else {
					for (int k = x1; k < x2; k++) {
						if (a[i][k] == 2) {
							flag = false;
							break;
						}
					}
					if (flag) {
						ret += solve(x1, y1, x2, i, 0)
							* solve(x1, i+1, x2, y2, 0);
					}
				}
			}
		}
	}
	return ret;
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
		}
	}
	ans = solve(0, 0, N, N, 0) + solve(0, 0, N, N, 1);
	cout << (!ans ? -1 : ans) << "\n";
}