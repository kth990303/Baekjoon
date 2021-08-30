// 210830 #22981 휴먼파이프라인 Gold V
// greedy, sort O(NlgN)
#include <iostream>
#include <algorithm>
#include <vector>
#define all(v) (v).begin(), (v).end()
#define press(v) (v).erase(unique(all(v)), (v).end())
using namespace std;
typedef long long ll;
const int MAX = 200001;
const ll LNF = 1e18;
ll N, K, ans = LNF, F1, F2, F;
vector<ll> v;
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N >> K;
	v.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> v[i];
	}
	sort(all(v));
	for (ll i = 0; i < N - 1; i++) {
		F1 += v[0];
		F2 = v[i + 1] * (N - i - 1);
		F = F1 + F2;
		ans = min(ans, K / F + (bool)(K % F));
	}
	cout << ans << "\n";
}