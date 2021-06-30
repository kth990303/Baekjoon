// 210630 #16438 ¿ø¼þÀÌ ½ºÆ÷Ã÷ Gold III
// divide_conquer (use binary_search, segtree logic)
// 2^7=128, so N<=99 can make all different
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
const int MAX = 100;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
int N, cnt;
vector<string> ans(7);
void solve(int k, int s, int e) {
	if (s >= e)
		return;
	cnt = max(cnt, k);
	int mid = (s + e) / 2;
	for (int i = s; i <= mid; i++) {
		ans[k][i] = 'A';
	}
	for (int i = mid + 1; i <= e; i++) {
		ans[k][i] = 'B';
	}
	solve(k + 1, s, mid);
	solve(k + 1, mid + 1, e);
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < 7; i++) {
		ans[i].resize(N);
	}
	solve(0, 0, N - 1);
	for (int i = 0; i < 7; i++) {
		for (int j = 0; j < N; j++) {
			if (ans[i][j])
				cout << ans[i][j];
			else if (!j)
				cout << (ans[i][j] = ans[i - 1][j]);
			else
				cout << (ans[i][j] = 1 - ans[i][j - 1] + 2*'A');
		}
		cout << "\n";
	}
}