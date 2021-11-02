// 210913 #2015 수들의 합4 Gold V
// prefix_sum
// can count before prefix_sum O(N) with map/set
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
const int MAX = 200001;
ll N, K, a[MAX], p[MAX], ans;
map<ll, int> m;
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> K;
	for (int i = 1; i <= N; i++) {
		cin >> a[i];
		p[i] = p[i - 1] + a[i];
		ans += m[p[i] - K];
		m[p[i]]++;
		if (p[i] == K)
			ans++;
	}
	cout << ans << "\n";
}