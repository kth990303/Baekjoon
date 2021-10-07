// 211007 #2631 줄세우기 Gold V
// LIS O(nlgn)
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
typedef pair<pi, int> pii;
const int MAX = 204;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
int N, a[MAX];
vector<int> v, ans;
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	for (int i = 0; i < N; i++) {
		int cur = lower_bound(ans.begin(), ans.end(), v[i]) - ans.begin();
		if (cur < ans.size())
			ans[cur] = v[i];
		else
			ans.push_back(v[i]);
	}
	cout << N-ans.size() << "\n";
}