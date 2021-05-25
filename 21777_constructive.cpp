// 210525 #21777 리버스 가희와 프로세스1
// constructive, greedy
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
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MAX = 1000001;
const int INF = 0x3f3f3f3f;
const ll LNF = 1e18;
const int MOD = 1e9 + 7;
int N, a[MAX], p, cnt[MAX], ans;
pi d[MAX];
int main() {
	cin.tie(0);
	cout.tie(0);
	ios::sync_with_stdio(false);

	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> a[i];
		cnt[a[i]]++;
		if (i && a[i - 1] >= a[i])
			p++;
		if (cnt[a[i]] > 1) {
			d[a[i]].first++;
			continue;
		}
		ans++;
		d[a[i]] = { cnt[a[i]], p };
	}
	cout << ans << "\n";
	for (int i = 1; i < MAX; i++) {
		if (cnt[i]) {
			cout << i << " " << d[i].first << " " << p - d[i].second + 1 << "\n";
		}
	}
	
}