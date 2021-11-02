// 211011 #1033 Ä¬Å×ÀÏ Gold II
// dfs, tree, euclidean
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
const int MAX = 100001;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
ll N, ans[10], a[10], b[10], p[10], q[10], num = 1;
vector<int> v[10];
ll gcd(ll a, ll b) {
	ll r = a % b;
	if (!r) return b;
	return gcd(b, r);
}
void dfs(int cur, int prev) {
	for (auto i : v[cur]) {
		if (prev == i)
			continue;
		for (int k = 0; k < N - 1; k++) {
			if (a[k] == i && b[k] == cur) {
				ans[i] = ans[cur]/q[k];
				ans[i] *= p[k];
				dfs(i, cur);
			}
			else if (a[k] == cur && b[k] == i) {
				ans[i] = ans[cur] / p[k];
				ans[i] *= q[k];
				dfs(i, cur);
			}
		}
	}
}
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	fill(ans, ans + 10, 1);
	for (int i = 0; i < N-1; i++) {
		cin >> a[i] >> b[i] >> p[i] >> q[i];
		if (a[i] > b[i]) {
			swap(a[i], b[i]);
			swap(p[i], q[i]);
		}
		int r = gcd(p[i], q[i]);
		p[i] /= r;
		q[i] /= r;
		v[a[i]].push_back(b[i]);
		v[b[i]].push_back(a[i]);
		num *= p[i] * q[i];
	}
	fill(ans, ans + 10, num);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				if (a[k] == i && b[k] == j) {
					if (p[k] < q[k]) {
						ans[i] = ans[j] / q[k];
						ans[i] *= p[k];
						dfs(i, j);
					}
					else if (p[k] >= q[k]) {
						dfs(j, i);
					}
				}
			}
		}
	}
	ll r = num;
	for (int i = 0; i < N; i++) {
		r = gcd(r, ans[i]);
	}
	for (int i = 0; i < N; i++)
		cout << ans[i] / r << " ";
}