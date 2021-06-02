// 210602 #6597 트리 복구 Gold III
// preorder, inorder -> postorder
// recursion
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
const int MAX = 3001;
const int INF = 0x3f3f3f3f;
const int MOD = 1e9 + 7;
string s1, s2;
void dfs(int idx, int s, int e) {
	if (s >= e)
		return;
	int k = s2.find(s1[idx]);
	dfs(idx + 1, s, k);
	dfs(idx + (k - s) + 1, k + 1, e);
	cout << s1[idx];
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	while (cin >> s1 >> s2) {
		dfs(0, 0, s2.length());
		cout << "\n";
	}
}