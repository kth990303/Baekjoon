// 211109 #2568 ภüฑ๊มู-2 Platinum V
// LIS O(nlgn) print arrays index
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
const int MAX = 100011;
const double INF = 0x3f3f3f3f;
const ll LNF = 1e16;
const int MOD = 1e9 + 7;
int N, M, cnt, rev[500011];
vector<pi> tmp, ans;
vector<int> v, res;
bool vis[500011];
int main() {
	cin.tie(0)->sync_with_stdio(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int n1, n2;
		cin >> n1 >> n2;
		rev[n2] = n1;
		tmp.push_back({ n1,n2 });
	}
	sort(all(tmp));
	for (int i = 0; i < N; i++) {
		int n = tmp[i].second;
		if (v.empty() || v.back() < n) {
			v.push_back(n);
			ans.push_back({ cnt,n });
			M = max(M, cnt);
			cnt++;
		}
		else {
			int idx = lower_bound(all(v), n) - v.begin();
			v[idx] = n;
			ans.push_back({ idx, n });
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--) {
		if (M == ans[i].first) {
			res.push_back(ans[i].second);
			vis[rev[ans[i].second]] = true;
			M--;
		}
	}
	cout << N - res.size() << "\n";
	for (int i = 0; i < tmp.size(); i++) {
		if (!vis[tmp[i].first])
			cout << tmp[i].first << "\n";
	}
}