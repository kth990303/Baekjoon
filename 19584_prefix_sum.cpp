// 210815 #19584 ³­°³¹ß Gold III
// prefix_sum + sweeping
#include <iostream>
#include <algorithm>
#include <vector>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
typedef pair<int, int> pi;
const int MAX = 200001;
int N, M;
ll p[MAX], d[MAX], ans;
vector<int> road, tmp;
vector<pair<int, pi>> v;
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int x, y;
		cin >> x >> y;
		road.push_back(y);
		tmp.push_back(y);
	}
	sort(all(tmp));
	while (M--) {
		int n1, n2;
		ll cost;
		cin >> n1 >> n2 >> cost;
		n1--; n2--;
		int h1 = road[n1];
		int h2 = road[n2];
		if (h1 > h2)
			swap(h1, h2);
		int idx1 = lower_bound(all(tmp), h1) - tmp.begin();
		int idx2 = upper_bound(all(tmp), h2) - tmp.begin();
		p[idx1] += cost;
		p[idx2] -= cost;
	}
	ll tmp = 0;
	for (int i = 0; i < N; i++) {
		tmp += p[i];
		d[i] += tmp;
	}
	for (int i = 0; i < N; i++) {
		ans = max(ans, d[i]);
	}
	cout << ans << "\n";
}