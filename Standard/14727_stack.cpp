// 211020 #14727 ÆÛÁñÀÚ¸£±â Platinum V
// histogram rectangle -> stack O(N)
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
const int MAX = 100011;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
ll N, a[MAX], ans, h;
vector<ll> v;
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> a[i];
	for (int i = 0; i <= N; i++) {
		while (!v.empty() && a[v.back()] > a[i]) {
			h = a[v.back()];
			v.pop_back();
			if (v.empty())
				ans = max(ans, h * i);
			else
				ans = max(ans, h * (i - v.back() - 1));
		}
		v.push_back(i);
	}
	cout << ans << "\n";
}