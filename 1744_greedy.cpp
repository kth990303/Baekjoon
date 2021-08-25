// 210825 #1744 ¼ö¹­±â Gold IV
// greedy + sort (case_work)
#include <iostream>
#include <vector>
#include <algorithm>
#define all(v) (v).begin(), (v).end()
using namespace std;
typedef long long ll;
const int MAX = 10001;
ll N, ans, cnt;
vector<ll> v1, v2;
int main() {
	cin.tie(0)->sync_with_stdio(0);

	cin >> N;
	for (int i = 0; i < N; i++) {
		ll n;
		cin >> n;
		if (n > 0)
			v1.push_back(n);
		else
			v2.push_back(n);
	}
	sort(all(v1), greater<ll>()), sort(all(v2));
	int cnt1 = v1.size() / 2;
	int cnt2 = v2.size() / 2;
	for (int i = 0; i < cnt1; i++) {
		if (v1[i * 2] == 1 || v1[i * 2 + 1] == 1)
			ans += v1[i * 2] + v1[i * 2 + 1];
		else
			ans += v1[i * 2] * v1[i * 2 + 1];
	}
	int num = v1.size();
	if (num % 2)
		ans += v1[num - 1];
	for (int i = 0; i < cnt2; i++) {
		ans += v2[i * 2] * v2[i * 2 + 1];
	}
	num = v2.size();
	if (num % 2)
		ans += v2[num - 1];
	cout << ans << "\n";
}